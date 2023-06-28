/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:27:23 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/24 23:25:46 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

int	ft_ctoi(char c)
{
	return (c - '0');
}

char	ft_stoc(size_t size)
{
	return ((char)(size + '0'));
}

bool	ft_check_open(int fd)
{
	if (fd == -1)
	{
		return (false);
	}
	return (true);
}

bool	ft_check_read(int fd)
{
	char	*buf;

	buf = malloc(sizeof(char));
	if (buf == NULL)
		return (false);
	if (read(fd, buf, 0) == -1)
	{
		free(buf);
		return (false);
	}
	free(buf);
	return (true);
}
