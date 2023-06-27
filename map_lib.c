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

void get_map_obstacle_count(int x, int y)
{
	(void)x;
	(void)y;
	int i=0, j=0;
	char str[6][12] = {
			"...........",
			".......o....",
			"............",
			"...o........",
			"............",
			"............"
	};

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

	int		arr[6][12];
	i = 0;
	j = 0;
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
	j = 0;
	while(i < 6)
	{
		j = 0;
		while(j < 12)
		{
			if(i == 0)
				arr[i][j] = arr[i][j]+arr[i][j-1];
			else if(j == 0)
				arr[i][j] = arr[i][j]+arr[i-1][j];
			else
				arr[i][j] = arr[i][j]+arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
			printf("%d", arr[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
//	while(i < 6)
//	{
//		j = 0;
//		while(j < 12)
//		{
//			printf("%c", str[i][j]);
//			j++;
//		}
//		i++;
//		printf("\n");
//	}
//	printf("\n");
//
///*
//	int arr[6][12];
//	i = 0;
//	j = 0;
//	while(i < 6)
//	{
//		j = 0;
//		while(j < 12)
//		{
//			if (str[i][j] == '.')
//				arr[i][j] = 0;
//			if (str[i][j] == 'o')
//				arr[i][j] = 1;
//			printf("%d", arr[i][j]);
//			j++;
//		}
//		i++;
//		printf("\n");
//	}
//	printf("\n");
//
//
//	i = 0;
//	j = 0;
//	while(i < 6)
//	{
//		j = 0;
//		while(j < 12)
//		{
//			if(i == 0)
//				arr[i][j] = arr[i][j]+arr[i][j-1];
//			else if(j == 0)
//				arr[i][j] = arr[i][j]+arr[i-1][j];
//			else
//				arr[i][j] = arr[i][j]+arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
//			printf("%d", arr[i][j]);
//			j++;
//		}
//		i++;
//		printf("\n");
//	}
//	printf("\n");
//	return ;
//	i = 0;
//	while(i < y)
//	{
//		j = 0;
//		while (j < x)
//		{
//			if (str[i][j] == '.')
//				arr[i][j] = 0;
//			if (str[i][j] == 'o')
//				arr[i][j] = 1;
//			printf("%d", arr[i][j]);
//			j++;
//		}
//		i++;
//		printf("\n");
//	}
//	printf("\n");
//
//	i = 0;
//	while(i < 6)
//	{
//		j = 0;
//		while(j < 12)
//		{
//			if(i == 0)
//				arr[i][j] = arr[i][j]+arr[i][j-1];
//			else if(j == 0)
//				arr[i][j] = arr[i][j]+arr[i-1][j];
//			else
//				arr[i][j] = arr[i][j]+arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
//			printf("%d", arr[i][j]);
//			j++;
//		}
//		i++;
//		printf("\n");
//	}
//	printf("\n");
//
////	i = 0;
////	j = 0;
////	int n = 1;
////	int s = 0;
////	int size = 1;
////	while(i < 6)
////	{
////		j = 0;
////		while(j < 12&& (i + n <=7))
////		{
////			s = 0;
////			n = size;
////			while(s == 0 && (j + n <= 13))
////			{
////				printf("i=%d", i);
////				printf("j=%d", j);
////				printf("s=%d", s);
////				printf("n=%d", n);
////				printf("v=%du ", arr[i+n-1][j+n-1]);
////				if(i == 0 || j == 0)
////				{
////					s = arr[i+n-1][j+n-1];
////					printf("s1=%d", s);
////				}
////				else
////				{
////					s = arr[i+n-1][j+n-1] - arr[i][j-n] - arr[i-n][j] + arr[i-n][j-n];
////					printf("s1=%d", s);
////				}
////				if (s>0)
////				{
////					size = n;
////					printf("size=%d", size);
////				}
////				n++;
////				printf("\n");
////			}
////			j++;
////		}
////		i++;
////		printf("\n");
////	}
////	i = 0;
////	while(i < y)
////	{
////		j = 0;
////		while(j < x)
////		{
////			while(i)
////			arr[i][j] = arr[i][j]+arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
////			printf("%d", arr[i][j]);
////			j++;
////		}
////		i++;
////		printf("\n");
////	}
////	j = 0;
////	i = 0;
////	int j_save, i_save;
////	while (i < y)
////	{
////		while (j < x)
////		{
////			if (str[i][j] == 'o')
////			{
////				i_save = i;
////				j_save = j;
////				while(i_save < y)
////				{
////					while (j_save < x)
////					{
////						arr[a][j]++;
////
////					}
////
////				}
////			}
////			printf("%d", arr[i][j]);
////			j++;
////		}
////		i++;
////		printf("\n");
////	}
////	printf("\n");
//*/
}