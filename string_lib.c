/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:23:47 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 09:23:48 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// find address of \0 "str" and return the offset from string start "save"
//"str" - "save"
size_t	ft_strlen(const char *str)
{
	const char	*save;

	save = str;
	while (*str != '\0')
		str++;
	return (str - save);
}

// count occurences of char "chr" in string "str"
size_t	ft_count_char(const char *str, char chr)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
	{
		if (*str == chr)
			counter++;
		str++;
	}
	return (counter);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// Have size with number of char
// until ':' and '\n'
size_t	strlen_until_char(const char *str, char c)
{
	size_t	size;

	size = 0;
	while (*str && *str != c)
	{
		str++;
		++size;
	}
	if (*str == '\0')
		return (-1);
	return (size);
}

size_t	strnlen_until_char(const char *str, char c, size_t n)
{
	size_t	size;

	size = 0;
	while (*str != c && n)
	{
		str++;
		++size;
		n--;
	}
	return (size);
}

const char	*ft_strchr(const char *str, char c)
{
	while (*str != '\0' && *str != c)
		str++;
	if (*str == '\0')
		return (NULL);
	return (str);
}