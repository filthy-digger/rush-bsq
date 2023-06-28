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

const char	*ft_strchr(const char *str, char c)
{
	while (*str != '\0' && *str != c)
		str++;
	if (*str == '\0')
		return (NULL);
	return (str);
}
