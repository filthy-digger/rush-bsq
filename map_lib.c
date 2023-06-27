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

void	get_map_obstacle_count(int x, int y, char map_string[y][x])
{
	int	**arr;
	int	d_y;
	int	d_x;
	int	size;

	arr = malloc(y * sizeof(int *));
	for (int i = 0; i < y; i++)
	{
		arr[i] = malloc(x * sizeof(int));
	}
	int j, i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("%c", map_string[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (map_string[i][j] == '.')
				arr[i][j] = 0;
			if (map_string[i][j] == 'o')
				arr[i][j] = 1;
			printf("%d", arr[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((i != 0) && (j != 0))
				arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] - arr[i
					- 1][j - 1];
			else if (j != 0)
				arr[i][j] = arr[i][j] + arr[i][j - 1];
			else if (i != 0)
				arr[i][j] = arr[i][j] + arr[i - 1][j];
			printf("%d", arr[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
	d_y = 2;
	d_x = 6;
	size = get_best_size(arr, d_y, d_x);
	printf("%d", size);
	printf("\n");
}

int	get_obstacles(int *const *arr, t_point a, t_point b, t_point c, t_point d)
{

/*
	c1			  c2
	-----------------------
	|             |    |  |
	|   A         | B  |  |
	|_____________|____|  |  r1
	|             |    |  |
	|    C        |  D |  |
	|_____________|____|  |  r2
	|_____________________|
*/
	if (a.x >= 0 && a.y >= 0)
	{
		return arr[d.y][d.x] - arr[c.y][c.x] - arr[b.y][b.x] + arr[a.y][a.x];
	}
/*
				  c2
	-----------------------
	|             |       |
	|   B         |       |
	|_____________|       |  r1
	|             |       |
	|    D        |       |
	|_____________|       |  r2
	|_____________________|
*/
	else if (b.x >= 0 && b.y >= 0)
	{
		return arr[d.y][d.x] - arr[b.y][c.x];
	}
/*
	c1			  c2
	-----------------------
	|             |    |  |
	|   C         | D  |  |
	|_____________|____|  |  r2
	|                     |
	|                     |
	|                     |
	|_____________________|
*/
	else if (c.x >= 0 && c.y >= 0)
	{
		return arr[d.y][d.x] - arr[c.y][c.x];
	}
/*
				  c2
	-----------------------
	|             |       |
	|   D         |       |
	|_____________|       |  r2
	|                     |
	|                     |
	|                     |
	|_____________________|
*/
	return arr[d.y][d.x];
}

int get_size(t_point a, t_point b, t_point c, t_point d)
{
/*
          a.x = c.x | b.x = d.x
	-----------------------
	|             |    |  |
	|   A         | B  |  |
	|_____________|____|  |  a.y = b.y
	|             |    |  |
	|    C        |  D |  |
	|_____________|____|  |  d.y = c.y
	|_____________________|
*/
	if (a.x >= 0 && a.y >= 0)
	{
		return d.y - a.y;
	}
/*
				d.x = b.x
	-----------------------
	|             |       |
	|   B         |       |
	|_____________|       |  b.y
	|             |       |
	|    D        |       |
	|_____________|       |  d.y
	|_____________________|
*/
	else if (b.x >= 0 && b.y >= 0)
	{
		return d.y - b.y;
	}
/*
			     c.x  d.x
	-----------------------
	|             |    |  |
	|   C         | D  |  |
	|_____________|____|  |  d.y = c.y
	|                     |
	|                     |
	|                     |
	|_____________________|
*/
	else if (c.x >= 0 && c.y >= 0)
	{
		return d.x - c.x;
	}
/*
				  d.x
	-----------------------
	|         |           |
	|   D     |           |
	|_________|           |  d.y
	|                     |
	|                     |
	|                     |
	|_____________________|
*/
	else return d.y;
}

	int get_best_size(int *const *arr, int d_y, int d_x)
{
	int	a_y;
	int	a_x;
	int	b_y;
	int	b_x;
	int	c_y;
	int	c_x;
	int	obstacles;
	int	size;

	obstacles = 0;
	a_y = d_y;
	a_x = d_x;
	b_x = d_x;
	c_y = d_y;
	while (obstacles == 0 && ((a_y >= 0) && (a_x >= 0)))
	{
		a_y--;
		a_x--;
		b_y = a_y;
		c_x = a_x;
		if ((a_y >= 0) && (a_x >= 0))
		{
			obstacles = arr[d_y][d_x] - arr[c_y][c_x] - arr[b_y][b_x]
				+ arr[a_y][a_x];
		}
		else if (a_x >= 0)
		{
			obstacles = arr[d_y][d_x] - arr[c_y][c_x];
		}
		else if (a_y >= 0)
		{
			obstacles = arr[d_y][d_x] - arr[b_y][b_x];
		}
		else
		{
			obstacles = arr[d_y][d_x];
		}
	}
	if (a_y < a_x)
		size = (d_x - a_x - 1);
	else if (a_y > a_x)
		size = (d_y - a_y - 1);
	else
		size = (d_y - a_y);
	return (size);
}
