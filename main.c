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

int	get_fd(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (!ft_check_open(fd) || !ft_check_read(fd))
		ft_putstr("map error\n");
	return (fd);
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	size_t	file_size;

	if (argc != 1)
	{
		i = 1;
		while (i < argc)
		{
			fd = get_fd(argv[i]);
			if (fd != -1)
			{
				file_size = ft_get_fsize(fd);
				if (file_size != 0)
				{
					fd = get_fd(argv[i]);
					if (fd != -1)
						map_solve(ft_get_file(fd, file_size));
				}
			}
			i++;
		}
	}
	else
		map_solve(ft_get_stdin_string());
	return (0);
}
