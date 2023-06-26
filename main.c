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

	i = 0;
	if (argc != 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (check_open_file(fd) == false || check_read_file(fd) == false)
			{
				ft_putstr("map error\n");
			}
			file_size = get_file_size(fd);

			fd = open(argv[i], O_RDONLY);
			if (!check_open_file(fd) || !check_read_file(fd))
			{
				ft_putstr("map error\n");
			}
			map_string = get_file_string(fd, file_size);
//			if (file_size == 257)
//				printf("true");
//			close(fd);
//			size_t lines = ft_count_char(map_string, '\n');
//			if (map_string[0] == '9')
//				printf("true");
			free(map_string);
//			ft_putnbr(lines);
			/*
						if (fd > 0) // check if map is valid
						{
							str = read...(fd, ..);
							... function to find square close(fd);
						}
						else
			*/
			i++;
		}
	}
	else
	{
		/*
				Should there be no passed arguments,
					your program must be able to read on the standard input
		*/
	}
	return (0);
}