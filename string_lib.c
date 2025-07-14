/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argabaso <argabaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:23:47 by agabasov          #+#    #+#             */
/*   Updated: 2025/07/14 22:24:31 by argabaso         ###   ########.fr       */
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

char	*ft_strchr(char *str, char c)
{
	while (*str != '\0' && *str != c)
		str++;
	if (*str == '\0')
		return (NULL);
	return (str);
}
