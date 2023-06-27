/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:20:16 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 09:20:24 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// copy from address src to address dst without managing overlap
void	*ft_memcpy(void *dst0, const void *src0, size_t size)
{
	char		*dst;
	const char	*src;

	dst = (char *)dst0;
	src = (const char *)src0;
	if (!(size == 0 || dst == src) && ((unsigned long)dst < (unsigned long)src))
	{
		while (size)
		{
			*dst++ = *src++;
			size--;
		}
	}
	else if (!(size == 0 || dst == src))
	{
		dst += size;
		src += size;
		while (size)
		{
			*dst-- = *src--;
			size--;
		}
	}
	return (dst0);
}

// check if overlap. use temp buffer to workaround
void	*ft_memmove(void *dst0, const void *src0, size_t size)
{
	char		*dst;
	const char	*src;
	void		*temp_buf;

	dst = (char *)dst0;
	src = (const char *)src0;
	if (size == 0 || dst == src)
		return (dst0);
	if (((unsigned long)dst + size < (unsigned long)src) || ((unsigned long)src
			+ size < (unsigned long)dst))
		return (ft_memcpy(dst0, src0, size));
	else
	{
		temp_buf = malloc(size * sizeof(char));
		if (temp_buf == NULL)
		{
			errno = ENOMEM;
			return (NULL);
		}
		ft_memcpy(temp_buf, src0, size);
		ft_memcpy(dst0, temp_buf, size);
		free(temp_buf);
		return (dst0);
	}
}

// give space memory to dst0 with malloc
void	*ft_realloc(void *src, size_t src_size, size_t new_size)
{
	void	*dst;

	dst = malloc(new_size);
	if (dst == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return ((ft_memcpy(dst, src, src_size)));
}
