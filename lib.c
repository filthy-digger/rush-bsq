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

bool	check_value_arg(char *str)
{
	while (*str == ' ' || (*str >= '\t' & *str <= '\r'))
		str++;
	while (*str == '+')
		str++;
	return (*str >= '0' && *str <= '9');
}

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

// Switch int to char in ASCII (+ 48)
char	ft_itoc(int i)
{
	return ((char)(i + '0'));
}
/*
i = 1;
while (i < (value.end - value.current) && value.current[i] == 0)
{
if (value.current[i] != 0)
{
all_zeros = false;
}
i++;
}
*/
