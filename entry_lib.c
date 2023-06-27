/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:56:00 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 15:03:32 by sgiazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// show entry - check if works
void	show_entry(t_entry entry)
{
	ft_putstr("key =");
	ft_putstrn(entry.key, entry.key_len);
	ft_putstr("\nkey_length =");
	ft_putnbr(entry.key_len);
	ft_putstr("\nvalue = ");
	ft_putstrn(entry.value, entry.value_len);
	ft_putstr("\nvalue_length =");
	ft_putnbr(entry.value_len);
	ft_putchar('\n');
}

// parse the string to get an entry struct
// used in get_dict to write every struct and to separate it
t_entry	get_entry(char *str)
{
	t_entry	entry;
	size_t	sep_value;
	size_t	sep_to_key;
	size_t	key_to_sep;

	entry.key = str;
	key_to_sep = strlen_until_char(entry.key, ':');
	entry.key_len = strnlen_until_char(entry.key, ' ', key_to_sep);
	sep_to_key = strlen_until_char(entry.key + key_to_sep, '\n');
	sep_value = repeat_char_n(entry.key + key_to_sep + 1, ' ', sep_to_key) + 1;
	entry.value = entry.key + key_to_sep + sep_value;
	entry.value_len = sep_to_key - sep_value;
	entry.pad = (key_to_sep - entry.key_len) + (sep_to_key - entry.value_len)
		+ 1;
	return (entry);
}

void	swap_entries(t_entry *e1, t_entry *e2)
{
	t_entry	temp;

	temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}
