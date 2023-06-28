/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clio_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:24:59 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 11:25:00 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// write one character
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// write '\0' terminated string
void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

// write error message with details
void	ft_puterr(char *error_detail)
{
	write(2, error_detail, ft_strlen(error_detail));
}

void	ft_print_map(t_map map)
{
	int	j;
	int	i;

	i = 0;
	while (i < map.spec.number_of_lines)
	{
		j = 0;
		while (j < map.spec.line_length)
		{
			ft_putchar(map.lines[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
