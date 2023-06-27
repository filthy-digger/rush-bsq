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

t_specification	get_spec(char *map_string)
{
	t_char_vector	first_line;
	t_specification	specification;

	first_line.start = map_string;
	first_line.end = strchr(map_string, '\n');
	first_line.current = first_line.start;
	specification.full = first_line.end[-1];
	specification.obstacle = first_line.end[-2];
	specification.empty = first_line.end[-3];
	return (specification);
}
int	main(int argc, char **argv)
{
	int fd;
	int i;
	char *map_string;
	//	char *new_map_string;
	size_t file_size;
	//	ssize_t last_read_status;
	//	t_specification specification;

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
		file_size = 1;
		map_string = malloc(file_size);
		ssize_t last_read_status = read(0, map_string, 1);
		char *new_map_string;
		while (last_read_status != 0)
		{
			if (last_read_status == -1)
			{
				ft_putstr("map error\n");
				free(map_string);
				return (1);
			}
			new_map_string = malloc(file_size + 1);
			ft_memcpy(new_map_string, map_string, file_size);
			last_read_status = read(0, new_map_string + file_size, 1);
			free(map_string);
			map_string = new_map_string;
			file_size++;
		}
		map_string[file_size - 1] = '\0';
		ft_putstrn(map_string, file_size);
		ft_putsize(file_size);
	}
	return (0);
}