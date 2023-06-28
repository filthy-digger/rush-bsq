/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:03:35 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/28 14:03:37 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_specification	make_specification(const char *map_string)
{
	unsigned int	e;
	t_specification	spec;
	t_char_vector	first_line;

	spec.valid = false;
	first_line.start = map_string;
	first_line.end = strchr(first_line.start, '\n');
	if ((first_line.end != NULL) && (first_line.end - first_line.start >= 4))
	{
		spec.full = first_line.end[-1];
		spec.obstacle = first_line.end[-2];
		spec.empty = first_line.end[-3];
		if (spec.full != spec.obstacle && spec.obstacle != spec.empty
			&& spec.full != spec.empty)
		{
			first_line.current = first_line.end - 4;
			e = 0;
			spec.number_of_lines = 0;
			while (first_line.start <= first_line.current)
				spec.number_of_lines += ft_ctoi(*first_line.current--)
					* ft_power(10, e++);
			spec.valid = true;
		}
	}
	return (spec);
}

void	show_spec(t_specification specification)
{
	ft_putstr("empty = ");
	ft_putchar(specification.empty);
	ft_putstr("\nobstacle = ");
	ft_putchar(specification.obstacle);
	ft_putstr("\nfull = ");
	ft_putchar(specification.full);
	ft_putstr("\nnumber of lines = ");
	ft_putsize(specification.number_of_lines);
}
