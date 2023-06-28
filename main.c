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

t_map	make_map(const char *map_string, bool isfile)
{
	t_map	map;
	int	i;
	int	j;
	int line_length;

	char *line_end;
	map.spec = make_spec(map_string);
	map.valid = false;
	if (map.spec.valid && (ft_strlen(map.spec.first_line.end) > 1))
	{
		map.lines = malloc(map.spec.number_of_lines * sizeof(char *));
		if (map.lines == NULL)
		{
			ft_puterr("malloc error");
			exit(0);
		}
		line_end =  (char *) map.spec.first_line.end;
		i = 0;
		while (i < map.spec.number_of_lines)
		{
			if (ft_strlen(line_end) <= 1)
				return map;
			map.lines[i] =  (char *) (line_end + 1);
			line_end = (char *) ft_strchr(map.lines[i], '\n');
			if (line_end == NULL)
				return map;
			line_length = (int) (line_end - map.lines[i]);
			if (i == 0)
				map.spec.line_length = line_length;
			if (line_length != map.spec.line_length)
				return map;
			j = 0;
			while (j < map.spec.line_length)
			{
				if (map.lines[i][j] != map.spec.obstacle && map.lines[i][j] != map.spec.empty)
					return (map);
				j++;
			}
			i++;
		}
		if (isfile && strlen(line_end) != 1)
		{
			return map;
		}
		map.valid = true;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	int i;
	int fd;
	char *map_string;
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
			t_map map = make_map(map_string, true);
			i++;
			if (map.valid)
			{
//				print_map((int)map.spec.line_length, (int) map.spec.number_of_lines, map.lines);
				get_map_obstacle_count(map.spec.line_length, map.spec.number_of_lines, map.lines);
//				show_spec(map.spec);
//				ft_putchar('\n');
			}
			else
				ft_putstr("map error\n");
			free(map_string);
		}
	}
	else
	{
		map_string = get_stdin_string();
		ft_putstr(map_string);
//		ft_putsize(ft_strlen(map_string));
		free(map_string);
	}
	return (0);
}