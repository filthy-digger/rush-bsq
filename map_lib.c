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

void	get_map_obstacle_count(t_map map)
{
	int	**arr;
	int	i;

	arr = malloc(map.spec.number_of_lines * sizeof(int *));
	if (arr == NULL)
	{
		ft_putstr("malloc error");
		exit(0);
	}
	i = 0;
	while (i < map.spec.number_of_lines)
	{
		arr[i] = malloc(map.spec.line_length * sizeof(int));
		i++;
	}
	preset_obstacles(arr, map);
	set_all_obstacle_count(map, arr);
	show_solution(get_best_solution(arr, map), map);
	i = 0;
	while (i < map.spec.number_of_lines)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	show_solution(t_solution solution, t_map map)
{
	int	j;
	int	i;

	i = 0;
	while (i < map.spec.number_of_lines)
	{
		j = 0;
		while (j < map.spec.line_length)
		{
			if (solution.size && (j <= (solution.d).x) && ((solution.d).x
					- solution.size < j) && (i <= (solution.d).y)
				&& ((solution.d).y - solution.size < i))
				ft_putchar(map.spec.full);
			else
				ft_putchar(map.lines[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	set_all_obstacle_count(t_map map, int **obstacle_matrix)
{
	int	j;
	int	i;

	i = 0;
	while (i < map.spec.number_of_lines)
	{
		j = 0;
		while (j < map.spec.line_length)
		{
			if ((i != 0) && (j != 0))
				obstacle_matrix[i][j] = obstacle_matrix[i][j]
					+ obstacle_matrix[i][j - 1] + obstacle_matrix[i - 1][j]
					- obstacle_matrix[i - 1][j - 1];
			else if (j != 0)
				obstacle_matrix[i][j] = obstacle_matrix[i][j]
					+ obstacle_matrix[i][j - 1];
			else if (i != 0)
				obstacle_matrix[i][j] = obstacle_matrix[i][j]
					+ obstacle_matrix[i - 1][j];
			j++;
		}
		i++;
	}
}

void	preset_obstacles(int **obstacle_matrix, t_map map)
{
	int	j;
	int	i;

	i = 0;
	while (i < map.spec.number_of_lines)
	{
		j = 0;
		while (j < map.spec.line_length)
		{
			if (map.lines[i][j] == map.spec.empty)
				obstacle_matrix[i][j] = 0;
			if (map.lines[i][j] == map.spec.obstacle)
				obstacle_matrix[i][j] = 1;
			j++;
		}
		i++;
	}
}

t_map	make_map(const char *map_string)
{
	t_map map;
	int i;
	int j;
	int line_length;
	char *line_end;

	map.spec = make_spec(map_string);
	map.valid = false;
	if (map.spec.valid)
	{
		map.lines = malloc(map.spec.number_of_lines * sizeof(char *));
		if (map.lines == NULL)
		{
			ft_puterr("malloc error");
			exit(0);
		}
		if (ft_strlen(map.spec.first_line.end) > 1)
		{
			line_end = (char *)map.spec.first_line.end;
			i = 0;
			while (i < map.spec.number_of_lines)
			{
				if (ft_strlen(line_end) <= 1)
					return (map);
				map.lines[i] = (char *)(line_end + 1);
				line_end = (char *)ft_strchr(map.lines[i], '\n');
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
			}
			map.valid = ft_strlen(line_end) == 1;
		}
	}
	return (map);
}