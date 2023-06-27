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

void get_map_obstacle_count()
{
	char str[6][12] = {
			"...........o",
			".......o....",
			"............",
			"...o........",
			"............",
			"............"
	};
	int		**arr = malloc(6 * sizeof(int *));
	for (int i = 0; i < 6; i++)
	{
		arr[i] = malloc(12 * sizeof(int));
	}

	int j, i = 0;

	while(i < 6)
	{
		j = 0;
		while(j < 12)
		{
			printf("%c", str[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");

	i = 0;
	while(i < 6)
	{
		j = 0;
		while(j < 12)
		{
			if (str[i][j] == '.')
				arr[i][j] = 0;
			if (str[i][j] == 'o')
				arr[i][j] = 1;
			printf("%d", arr[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");


	i = 0;
	while(i < 6)
	{
		j = 0;
		while(j < 12)
		{
			if ((i == 0) && (j != 0))
			{
				arr[i][j] = arr[i][j] + arr[i][j - 1];
			}
			else if ((i != 0) && (j == 0))
			{
				arr[i][j] = arr[i][j] + arr[i - 1][j];
			}
			else if ((i != 0) && (j != 0))
			{
				arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] -
							arr[i - 1][j - 1];
			}
			printf("%d", arr[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}