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
	size_t	i;

	(void)isfile;
	map.spec = make_spec(map_string);
	map.valid = false;
	if (map.spec.valid && (ft_strlen(map.spec.first_line.end) > 1))
	{
		map.start.start = map.spec.first_line.end + 1;
		map.start.end = ft_strchr(map.start.start, '\n');
		if (map.start.end != NULL && (char_vec_length(map.start) != 0))
		{
			map.spec.line_length = char_vec_length(map.start);
			map.current = map.start;
			i = 1;
			while (i < map.spec.number_of_lines)
			{
				if (ft_strlen(map.current.end) <= 1)
					return map;
				map.current.start = map.current.end + 1;
				map.current.end = ft_strchr(map.current.start, '\n');
				if (map.current.end != NULL &&
				char_vec_length(map.current) != map.spec.line_length)
					return (map);
				map.current.current = map.current.start;
				while (map.current.current < map.current.end)
				{
					if (*map.current.current != map.spec.obstacle && *map.current.current != map.spec.empty)
						return (map);
					map.current.current++;
				}
				i++;
			}
			map.end = map.current;
			map.valid = true;
		}
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
				ft_putmap(map);
//				show_spec(map.spec);
				ft_putstr("\n");
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