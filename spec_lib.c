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

t_map_spec	make_spec(const char *map_string)
{
	unsigned int	e;
	t_map_spec		spec;

	spec.valid = false;
	spec.first_line.start = map_string;
	spec.first_line.end = ft_strchr(spec.first_line.start, '\n');
	if ((spec.first_line.end != NULL) && (spec.first_line.end
			- spec.first_line.start >= 4))
	{
		spec.full = spec.first_line.end[-1];
		spec.obstacle = spec.first_line.end[-2];
		spec.empty = spec.first_line.end[-3];
		if (spec.full != spec.obstacle && spec.obstacle != spec.empty
			&& spec.full != spec.empty)
		{
			spec.first_line.current = spec.first_line.end - 4;
			e = 0;
			spec.number_of_lines = 0;
			while (spec.first_line.start <= spec.first_line.current)
				spec.number_of_lines += ft_ctoi(*spec.first_line.current--)
					* ft_power(10, e++);
			spec.valid = true;
		}
	}
	return (spec);
}

void	show_spec(t_map_spec specification)
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
