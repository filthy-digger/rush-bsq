/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelaloy <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:36:21 by adelaloy          #+#    #+#             */
/*   Updated: 2023/06/26 15:53:29 by adelaloy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

int	main(int argc, char **argv)
{
	int i;
	int fd;
	char *map_string;
	size_t file_size;
	t_map map;

	if (argc != 1)
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (ft_check_open_file(fd) == false
				|| ft_check_read_file(fd) == false)
			{
				ft_putstr("map error\n");
				return (1);
			}
			file_size = ft_get_file_size(fd);
			fd = open(argv[i], O_RDONLY);
			if (!ft_check_open_file(fd) || !ft_check_read_file(fd))
			{
				ft_putstr("map error\n");
				return (1);
			}
			map_string = ft_get_file_string(fd, file_size);
			map = ft_make_map(map_string);
			if (map.valid)
			{
				ft_get_map_obstacle_count(map);
				ft_putchar('\n');
			}
			else
				ft_putstr("map error\n");
			if (map.spec.valid)
				free(map.lines);
			free(map_string);
			i++;
		}
	}
	else
	{
		map_string = ft_get_stdin_string();
		map = ft_make_map(map_string);
		if (map.valid)
		{
			ft_get_map_obstacle_count(map);
			ft_putchar('\n');
		}
		else
			ft_putstr("map error\n");
		if (map.spec.valid)
			free(map.lines);
		free(map_string);
	}
	return (0);
}