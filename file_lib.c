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
	if (read(fd, buf, 0) == -1)
	{
		free(buf);
		return (false);
	}
	free(buf);
	return (true);
}

size_t	ft_get_fsize(int fd)
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

char	*ft_get_file(int fd, size_t file_size)
{
	char	*file_str;

	if (file_size == 0)
		return (NULL);
	file_str = malloc((file_size + 1) * sizeof(char));
	if (file_str == NULL)
	{
		ft_putstr("malloc error");
		exit(1);
	}
	if (read(fd, file_str, (file_size + 1) * sizeof(char)) < 0)
	{
		free(file_str);
		close(fd);
		return (NULL);
	}
	file_str[file_size] = '\0';
	return (file_str);
}

char	*ft_get_stdin_string(void)
{
	size_t	file_size;
	ssize_t	last_read_status;
	char	*map_string;
	char	*new_map_string;

	file_size = 1;
	map_string = malloc(file_size);
	last_read_status = read(0, map_string, 1);
	while (last_read_status != 0)
	{
		if (last_read_status == -1)
		{
			ft_putstr("stdin read error\n");
			free(map_string);
			exit(1);
		}
		new_map_string = malloc(file_size + 1);
		ft_memcpy(new_map_string, map_string, file_size);
		last_read_status = read(0, new_map_string + file_size, 1);
		free(map_string);
		map_string = new_map_string;
		file_size++;
	}
	map_string[file_size - 1] = '\0';
	return (map_string);
}
