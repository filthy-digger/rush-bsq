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

t_map_spec	ft_make_spec(char *map_string)
{
	unsigned int	e;
	t_map_spec		spec;
	char			*current;
	char			*line_end;

	spec.valid = false;
	line_end = ft_strchr(map_string, '\n');
	if ((line_end != NULL) && (line_end - map_string >= 4))
	{
		spec.full = line_end[-1];
		spec.obstacle = line_end[-2];
		spec.empty = line_end[-3];
		if (spec.full != spec.obstacle && spec.obstacle != spec.empty
			&& spec.full != spec.empty)
		{
			current = line_end - 4;
			e = 0;
			spec.number_of_lines = 0;
			while (map_string <= current)
				spec.number_of_lines += ft_ctoi(*current--) * ft_power(10, e++);
			spec.valid = true;
		}
	}
	return (spec);
}

void	ft_show_spec(t_map_spec specification)
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
