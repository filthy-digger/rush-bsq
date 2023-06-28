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

void	get_map_obstacle_count(int x, int y, const char **map_string)
{
	int	**arr;
	int	i;

	arr = malloc(y * sizeof(int *));
	i = 0;
	while (i < y)
	{
		arr[i] = malloc(x * sizeof(int));
		i++;
	}
	//	print_map(x, y, map_string);
	preset_obstacles(x, y, map_string, arr);
	set_all_obstacle_count(x, y, arr);
	show_solution(x, y, map_string, get_best_solution(x, y, arr));
}

void	show_solution(int x, int y, const char **map_string,
		t_solution solution)
{
	int	j;
	int	i;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (solution.size && (j <= (solution.d).x) && ((solution.d).x
					- solution.size < j) && (i <= (solution.d).y)
				&& ((solution.d).y - solution.size < i))
				ft_putchar('x');
			else
				ft_putchar(map_string[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

t_solution	get_best_solution(int x, int y, int **arr)
{
	t_solution	best_solution;
	t_solution	solution;

	solution.d.x = 0;
	solution.d.y = 0;
	(best_solution.size) = 0;
	while (solution.d.y < y)
	{
		solution.d.x = 0;
		while (solution.d.x < x)
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

void	set_all_obstacle_count(int x, int y, int **obstacle_matrix)
{
	int	j;
	int	i;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
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

void	preset_obstacles(int x, int y, const char **map_string,
		int **obstacle_matrix)
{
	int	j;
	int	i;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map_string[i][j] == '.')
				obstacle_matrix[i][j] = 0;
			if (map_string[i][j] == 'o')
				obstacle_matrix[i][j] = 1;
			j++;
		}
		i++;
	}
}

void	print_map(int x, int y, const char **map_string)
{
	int	j;
	int	i;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putchar(map_string[i][j]);
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
