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

void	map_line_loop(t_map *m, char *line_end, int i, int j)
{
	int	line_length;

	while (i < m->spec.n)
	{
		if (ft_strlen(line_end) <= 1)
			return ;
		m->str[i] = (line_end + 1);
		line_end = ft_strchr(m->str[i], '\n');
		if (line_end == NULL)
			return ;
		line_length = (int)(line_end - m->str[i]);
		if (i == 0)
			m->spec.len = line_length;
		if (line_length != m->spec.len)
			return ;
		j = 0;
		while (j < m->spec.len)
		{
			if (m->str[i][j] != m->spec.obs && m->str[i][j] != m->spec.emp)
				return ;
			j++;
		}
		i++;
	}
	m->valid = ft_strlen(line_end) == 1;
}

t_map	ft_make_map(char *map_string)
{
	t_map	map;
	char	*line_end;

	map.spec = ft_make_spec(map_string);
	map.valid = false;
	if (map.spec.valid)
	{
		line_end = ft_strchr(map_string, '\n');
		(map).str = malloc((map).spec.n * sizeof(char *));
		if (map.str == NULL)
			return (map);
		map_line_loop(&map, line_end, 0, 0);
	}
	return (map);
}

void	map_solve(char *map_string)
{
	t_map	map;

	if (map_string == NULL)
	{
		ft_puterr("map error\n");
		return ;
	}
	(map) = ft_make_map(map_string);
	if ((map).valid)
	{
		ft_get_map_obstacle_count((map));
	}
	else
		ft_puterr("map error\n");
	if ((map).spec.valid)
		free((map).str);
	free(map_string);
}
