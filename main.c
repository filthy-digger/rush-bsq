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

// t_map	get_map(char *map_string, t_specification specification)
//{
//
//}

int	main(int argc, char **argv)
{
	int fd;
	int i;
	char *map_string;
	//	char *new_map_string;
	size_t file_size;
	//	ssize_t last_read_status;
	//	t_specification specification;

	const char *str[20]	= {
			".o..o...o.o..o......",
			"....o...............",
			"...o...o.......o....",
			"............o.......",
			"...o...........oo...",
			"....o...o.........o.",
			"o........o...o..o...",
			"....oo..........oo..",
			"oo.oo..o............",
			"o.o......o.........o",
			"...o..o.............",
			"....................",
			"..o................o",
			".........oo......o.o",
			"..o.o.o.....o.....o.",
			"......o.oo.o........",
			"..........o..o......",
			"..............o.....",
			"o...o......o..o....o",
			"........o..........."
	};
	get_map_obstacle_count(20, 20, &str[0]);
	return 0;
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
			size_t num_lines = ft_count_char(map_string, '\n');
			ft_putsize(num_lines);
			//				check if map is valid
			free(map_string);
			i++;
		}
	}
	else
	{
		map_string = get_stdin_string();
		ft_putstr(map_string);
	}
	return (0);
}