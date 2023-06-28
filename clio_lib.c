/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clio_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:24:59 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 11:25:00 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// write one character
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// write string for n characters
void	ft_putstrn(const char *str, size_t n)
{
	write(1, str, n);
}

// write '\0' terminated string
void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

// write error message with details
void	ft_puterr(char *error_detail)
{
	write(2, error_detail, ft_strlen(error_detail));
}

void	ft_putvec(t_char_vector vec)
{
	ft_putstrn(vec.start, char_vec_length(vec));
}
