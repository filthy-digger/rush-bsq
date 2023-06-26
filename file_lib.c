/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:20:06 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 09:20:07 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

bool	check_open_file(int fd)
{
	if (fd == -1)
	{
		ft_puterr("invalid path");
		return (false);
	}
	return (true);
}

bool	check_read_file(int fd)
{
	char	*buf;

	buf = malloc(sizeof(char));
	if (read(fd, buf, 0) == -1)
	{
		ft_puterr("cannot read");
		free(buf);
		return (false);
	}
	free(buf);
	return (true);
}

size_t	get_file_size(int fd)
{
	char	*buf;
	ssize_t	last_read_status;
	size_t	file_size;

	buf = malloc(sizeof(char));
	last_read_status = read(fd, buf, sizeof(char));
	file_size = 0;
	while (last_read_status != 0)
	{
		if (last_read_status == -1)
		{
			ft_putstr("map error\n");
			close(fd);
			free(buf);
			return (1);
		}
		last_read_status = read(fd, buf, sizeof(char));
		file_size++;
	}
	free(buf);
	close(fd);
	return (file_size);
}

char	*get_file_string(int fd, size_t file_size)
{
	ssize_t	last_read_status;
	char	*dict_str;

	if (file_size == 0)
		return (NULL);
	dict_str = malloc(file_size * sizeof(char));
	if (dict_str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	last_read_status = read(fd, dict_str, file_size * sizeof(char));
	if (last_read_status < 0)
	{
		free(dict_str);
		close(fd);
		return (NULL);
	}
	return (dict_str);
}
