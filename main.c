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
	t_specification specification;
	size_t file_size;

	i = 1;
	if (argc != 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (check_open_file(fd) == false || check_read_file(fd) == false)
			{
				ft_putstr("map error\n");
				return (1);
			}
			file_size = get_file_size(fd);
			fd = open(argv[i], O_RDONLY);
			if (!check_open_file(fd) || !check_read_file(fd))
			{
				ft_putstr("map error\n");
				return (1);
			}
			map_string = get_file_string(fd, file_size);
			i++;
			ft_putstr(map_string);
			specification = make_specification(map_string);
			if (!specification.valid)
				ft_putstr("map error\n");
			else
				show_spec(specification);
			ft_putstr("\n\n");
			free(map_string);
		}
	}
	else
	{
		map_string = get_stdin_string();
		ft_putstr(map_string);
		free(map_string);
	}
	return (0);
}