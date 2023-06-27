/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:27:23 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/24 23:25:46 by sgiazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

int	ft_ctoi(char c)
{
	return (c - '0');
}

size_t	repeat_char_n(const char *str, char c, size_t n)
{
	size_t	size;

	size = 0;
	while (*str == c && size < n)
	{
		str++;
		++size;
	}
	return (size);
}

char	ft_stoc(size_t size)
{
	return ((char)(size + '0'));
}

char	ft_itoc(int i)
{
	return ((char)(i + '0'));
}
