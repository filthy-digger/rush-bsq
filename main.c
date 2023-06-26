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

int		main(int argc, char **argv)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	if (argc != 1)
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd > 0) //check if map is valid
			{
				str = read... (fd, ..);
				...function to find square
				close(fd);
			}
			else
				write(1, "map error\n", 10);
			i++;
		}
	else
	{
		Should there be no passed arguments, your program must be able to read on the standard input	
	}
	return (0);
