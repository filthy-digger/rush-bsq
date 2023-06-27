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

void get_map_obstacle_count(int x, int y, char map_string[y][x])
{
	int		**arr = malloc(y * sizeof(int *));
	for (int i = 0; i < y; i++)
	{
		arr[i] = malloc(x * sizeof(int));
	}

	int j, i = 0;

	while(i < y)
	{
		j = 0;
		while(j < x)
		{
			printf("%c", map_string[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");

	i = 0;
	while(i < y)
	{
		j = 0;
		while(j < x)
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
	while(i < y)
	{
		j = 0;
		while(j < x)
		{
			if ((i != 0) && (j != 0))
				arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] -
							arr[i - 1][j - 1];
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


	i = 0;
	int best_size = 0;
	int size = 0;
	while(i < y)
	{
		j = 0;
		while(j < x)
		{
			if ((i != 0) && (j != 0))
				arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] -
							arr[i - 1][j - 1];
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
}