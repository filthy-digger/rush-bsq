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

unsigned long	ft_power(unsigned int b, unsigned int e)
{
	if (e == 0)
		return (1);
	else
		return (b * (ft_power(b, e - 1)));
}
