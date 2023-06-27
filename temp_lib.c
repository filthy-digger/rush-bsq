/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 09:05:01 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 09:05:02 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_putnbr_aux(int n)
{
	int		r;
	int		q;
	char	c;

	q = n / 10;
	r = n % 10;
	if (q > 0)
		ft_putnbr_aux(q);
	c = (char)(r + 48);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (-2147483648 == nb)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		ft_putnbr_aux(nb);
	}
}

void	ft_putsize(size_t size)
{
	size_t r;
	size_t q;

	q = size / 10;
	r = size % 10;
	if (q > 0)
		ft_putsize(q);
	ft_putchar(ft_itoc(r));
}