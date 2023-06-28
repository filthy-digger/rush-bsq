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

const char *g_str =
	"20.ox\n.o..o...o.o..o......\n....o...............\n...o...o.......o....\n............o.......\n...o...........oo...\n....o...o.........o.\no........o...o..o...\n....oo..........oo..\noo.oo..o............\no.o......o.........o\n...o..o.............\n....................\n..o................o\n.........oo......o.o\n..o.o.o.....o.....o.\n......o.oo.o........\n..........o..o......\n..............o.....\no...o......o..o....o\n........o...........\n";

/*
t_map	make_specification(char *map_string)
{
	t_specification	specification;
	t_map			map;
	t_char_vector	first_line;

	first_line.start = map_string;
	first_line.end = strchr(first_line.start,'\n');
	if (first_line.end == NULL)
		specification.valid = false;
	else
}
*/

//char **get_map(const char *map_string)

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