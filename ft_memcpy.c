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
	while (size)
	{
		*dst++ = *src++;
		size--;
	}
	return (dst0);
}