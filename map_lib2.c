/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lib2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:59:46 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/28 18:59:47 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

bool	alloc_arr(t_map *map, int i, int ***arr);

void	ft_get_map_obstacle_count(t_map map)
{
	int	**matrix;
	int	i;

	if (!alloc_arr(&map, 0, &matrix))
		return ;
	ft_preset_obstacles(matrix, map);
	ft_set_all_obstacle_count(map, matrix);
	ft_show_solution(ft_get_best_solution(matrix, map), map);
	i = 0;
	while (i < map.spec.n)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

bool	alloc_arr(t_map *map, int i, int ***arr)
{
	*arr = malloc(map->spec.n * sizeof(int *));
	if (*arr == NULL)
	{
		ft_puterr("map error\n");
		return (false);
	}
	i = 0;
	while (i < map->spec.n)
	{
		(*arr)[i] = malloc(map->spec.len * sizeof(int));
		if ((*arr)[i] == NULL)
			break ;
		i++;
	}
	if (i != map->spec.n && (*arr)[i--] == NULL)
	{
		while (0 <= i)
		{
			free((*arr)[i]);
			i--;
		}
		free(*arr);
		return (false);
	}
	return (true);
}

void	ft_show_solution(t_solution solution, t_map map)
{
	int	j;
	int	i;

	if (solution.size == 0)
	{
		ft_puterr("map error\n");
		return ;
	}
	i = 0;
	while (i < map.spec.n)
	{
		j = 0;
		while (j < map.spec.len)
		{
			if (solution.size && (j <= (solution.d).x) && ((solution.d).x
					- solution.size < j) && (i <= (solution.d).y)
				&& ((solution.d).y - solution.size < i))
				ft_putchar(map.spec.full);
			else
				ft_putchar(map.str[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	ft_set_all_obstacle_count(t_map map, int **obstacle_matrix)
{
	int	j;
	int	i;

	i = 0;
	while (i < map.spec.n)
	{
		j = 0;
		while (j < map.spec.len)
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

void	ft_preset_obstacles(int **obstacle_matrix, t_map map)
{
	int	j;
	int	i;

	i = 0;
	while (i < map.spec.n)
	{
		j = 0;
		while (j < map.spec.len)
		{
			if (map.str[i][j] == map.spec.emp)
				obstacle_matrix[i][j] = 0;
			if (map.str[i][j] == map.spec.obs)
				obstacle_matrix[i][j] = 1;
			j++;
		}
		i++;
	}
}
