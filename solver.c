/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:08:12 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/28 18:08:14 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

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
