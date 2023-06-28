/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:19:55 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/26 17:19:57 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_map	ft_make_map(char *map_string)
{
	t_map map;
	int i;
	int j;
	int line_length;
	char *line_end;

	map.spec = ft_make_spec(map_string);
	map.valid = false;
	if (map.spec.valid)
	{
		map.lines = malloc(map.spec.number_of_lines * sizeof(char *));
		if (map.lines == NULL)
		{
			ft_puterr("malloc error");
			exit(0);
		}
		line_end = ft_strchr(map_string, '\n');
		i = 0;
		while (i < map.spec.number_of_lines)
		{
			if (ft_strlen(line_end) <= 1)
				return (map);
			map.lines[i] = (line_end + 1);
			line_end = ft_strchr(map.lines[i], '\n');
			if (line_end == NULL)
				return (map);
			line_length = (int)(line_end - map.lines[i]);
			if (i == 0)
				map.spec.line_length = line_length;
			if (line_length != map.spec.line_length)
				return (map);
			j = 0;
			while (j < map.spec.line_length)
			{
				if (map.lines[i][j] != map.spec.obstacle
					&& map.lines[i][j] != map.spec.empty)
					return (map);
				j++;
			}
			i++;
			map.valid = ft_strlen(line_end) == 1;
		}
	}
	return (map);
}