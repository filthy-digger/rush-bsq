/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:13:22 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 09:13:24 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

size_t	char_vec_length(t_char_vector vec)
{
	return (vec.end - vec.start);
}

size_t	int_vec_length(t_int_vector vec)
{
	return (vec.end - vec.start);
}
t_int_vector	ft_strv_to_intv(t_char_vector str)
{
	t_int_vector	res_vec;

	res_vec.start = malloc((str.end - str.start) * sizeof(int));
	if (res_vec.start == NULL)
	{
		errno = ENOMEM;
		return (res_vec);
	}
	res_vec.current = res_vec.start;
	//	while (*str == ' ' || (*str >= '\t' & *str <= '\r'))
	//		str++;
	//	while (*str == '+')
	//		str++;
	//	while (*str == '0')
	//		*res_vec.current = ft_ctoi(*str++);
	while (*str.current >= '0' && *str.current <= '9')
		*((res_vec.current)++) = ft_ctoi(*(str.current++));
	res_vec.end = res_vec.current;
	return (res_vec);
}

unsigned long	ft_power(unsigned int b, unsigned int e)
{
	if (e == 0)
		return (1);
	else
		return (b * (ft_power(b, e - 1)));
}

// size_t	get_number_of_lines(t_char_vector str)
//{
//	size_t res;
//	res = 0;
//	int i;
//	str.current = str.end - 1;
//	while(str.start <= str.current)
//		res += ft_power(10,i);
//
//}