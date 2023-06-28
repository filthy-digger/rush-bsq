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
	//	print_map(map.spec.line_length, map.spec.number_of_lines, map.lines);
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

t_solution	get_best_solution(int **arr, t_map map)
{
	t_solution	best_solution;
	t_solution	solution;

	solution.d.x = 0;
	solution.d.y = 0;
	(best_solution.size) = 0;
	while (solution.d.y < map.spec.number_of_lines)
	{
		solution.d.x = 0;
		while (solution.d.x < map.spec.line_length)
		{
			solution.size = get_best_size(arr, solution.d);
			if (solution.size > (best_solution.size))
			{
				(best_solution.size) = solution.size;
				(best_solution.d) = solution.d;
			}
			solution.d.x++;
		}
		solution.d.y++;
	}
	return (best_solution);
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

void	print_map(t_map map)
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

int	get_obstacles(int **arr, t_solver_spec spec)
{
	if (spec.a.x >= 0 && spec.a.y >= 0)
	{
		return (arr[spec.d.y][spec.d.x] - arr[spec.c.y][spec.c.x]
			- arr[spec.b.y][spec.b.x] + arr[spec.a.y][spec.a.x]);
	}
	else if (spec.b.x >= 0 && spec.b.y >= 0)
	{
		return (arr[spec.d.y][spec.d.x] - arr[spec.b.y][spec.b.x]);
	}
	else if (spec.c.x >= 0 && spec.c.y >= 0)
	{
		return (arr[spec.d.y][spec.d.x] - arr[spec.c.y][spec.c.x]);
	}
	return (arr[spec.d.y][spec.d.x]);
}

int	get_size(t_solver_spec solver_spec)
{
	if (solver_spec.a.x >= 0 && solver_spec.a.y >= 0)
		return (solver_spec.d.y - solver_spec.a.y);
	else if (solver_spec.b.x >= 0 && solver_spec.b.y >= 0)
		return (solver_spec.d.y - solver_spec.b.y);
	else if (solver_spec.c.x >= 0 && solver_spec.c.y >= 0)
		return (solver_spec.d.x - solver_spec.c.x);
	if (solver_spec.d.y > solver_spec.d.x)
		return (solver_spec.d.x + 1);
	else
		return (solver_spec.d.y + 1);
}

int	get_best_size(int **arr, t_point d)
{
	t_solver_spec	solver_spec;
	int				best_size;

	best_size = 0;
	solver_spec.d = d;
	solver_spec.a.x = solver_spec.d.x - 1;
	solver_spec.a.y = solver_spec.d.y - 1;
	solver_spec.b.x = solver_spec.d.x;
	solver_spec.b.y = solver_spec.a.y;
	solver_spec.c.x = solver_spec.a.x;
	solver_spec.c.y = solver_spec.d.y;
	while ((get_obstacles(arr, solver_spec) == 0) && (solver_spec.a.x >= -1)
		&& (solver_spec.a.y >= -1))
	{
		best_size = get_size(solver_spec);
		solver_spec.a.x--;
		solver_spec.a.y--;
		solver_spec.b.y = solver_spec.a.y;
		solver_spec.c.x = solver_spec.a.x;
	}
	return (best_size);
}
t_map	make_map(const char *map_string, bool isfile)
{
	t_map	map;
	int		i;
	int		j;
	int		line_length;
	char	*line_end;

	map.spec = make_spec(map_string);
	map.valid = false;
	if (map.spec.valid)
	{
		map.lines = malloc(map.spec.number_of_lines * sizeof(char *));
		if (ft_strlen(map.spec.first_line.end) > 1)
		{
			if (map.lines == NULL)
			{
				ft_puterr("malloc error");
				exit(0);
			}
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
			if (isfile && strlen(line_end) != 1)
			{
				return (map);
			}
			map.valid = true;
		}
	}
	return (map);
}
