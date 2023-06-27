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
	int	size;
	t_point  d;

	arr = malloc(y * sizeof(int *));
	int j, i = 0;
	while (i < y)
	{
		arr[i] = malloc(x * sizeof(int));
		i++;
	}
	i = 0;
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
	d.x = 0;
	d.y = 0;
	int best_size = 0;
	t_point best_d;
	while (d.y < y)
	{
		d.x = 0;
		while (d.x < x)
		{
			size = get_best_size(arr,d);
			if (size > best_size)
			{
				best_size = size;
				best_d = d;
			}
			d.x++;
		}
		d.y++;
	}
	printf("%d", best_size);
	printf("\n");
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (best_size && (j <= best_d.x) && (best_d.x - best_size < j)
				&& (i <= best_d.y) && (best_d.y - best_size < i))
				printf("x");
			else
				printf("%c", map_string[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}

int	get_obstacles(int *const *arr, t_point a, t_point b, t_point c, t_point d)
{
	if (a.x >= 0 && a.y >= 0)
	{
		return arr[d.y][d.x] - arr[c.y][c.x] - arr[b.y][b.x] + arr[a.y][a.x];
	}
	else if (b.x >= 0 && b.y >= 0)
	{
		return arr[d.y][d.x] - arr[b.y][b.x];
	}
	else if (c.x >= 0 && c.y >= 0)
	{
		return arr[d.y][d.x] - arr[c.y][c.x];
	}
	return arr[d.y][d.x];
}

/*
  |----------------|---|......
  |....o...........|...|......
  |........A...o...|.B.|......
  |----------------a---b......
  |....o...........|...|......
  |........C......o|.D.|......
  |................|...|......
  |------o---------c---do.....
   ..o.......o................

  |----------------|---|......
  |....o...A.......|.B.|......
  |------------o---a---b......
  |................|...|......
  |....o...........|...|......
  |........C......o|.D.|......
  |................|...|......
  |------o---------c---do.....
   ..o.......o................
          a.x = c.x | b.x = d.x
	|-------------|----|---
	|             |    |  |
	|             |    |  |
	|_____________a____b  |  a.y = b.y
	|             |    |  |
	|             |    |  |
	|_____________c____d  |  d.y = c.y
	|_____________________|
				d.x = b.x
	-----------------------
	|             |       |
	|             |       |
	|_____________b       |  b.y
	|             |       |
	|             |       |
	|_____________d       |  d.y
	|_____________________|
			     c.x  d.x
	-----------------------
	|             |    |  |
	|             |    |  |
	|_____________c____d  |  d.y = c.y
	|                     |
	|                     |
	|                     |
	|_____________________|
        d.x
	-----------------------
	|                     |
	|----|                |
	|    |                |
	|----d                |  d.y
	|                     |
	|                     |
	|_____________________|
*/
int get_size(t_point a, t_point b, t_point c, t_point d)
{
	if (a.x >= 0 && a.y >= 0)
		return d.y - a.y;
	else if (b.x >= 0 && b.y >= 0)
		return d.y - b.y;
	else if (c.x >= 0 && c.y >= 0)
		return d.x - c.x;
	if (d.y > d.x)
		return d.x + 1;
	else
		return d.y + 1;
}

int get_best_size(int *const *arr, t_point d)
{
	t_point a;
	t_point b;
	t_point c;
	int best_size = 0;

	a.x = d.x - 1;
	a.y = d.y - 1;
	b.x = d.x;
	b.y = a.y;
	c.x = a.x;
	c.y = d.y;
	while (get_obstacles(arr,a,b,c,d) == 0 && (a.x >= -1 && a.y >= -1))
	{
		best_size = get_size(a,b,c,d);
		a.x--;
		a.y--;
		b.y = a.y;
		c.x = a.x;
	}
	return (best_size);
}
