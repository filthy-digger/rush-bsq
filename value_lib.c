/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:56:07 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/24 19:56:08 by agabasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// Read the string (argv put in main)
// Eleminate invalid characters (sp, 9 - 13, 0)
// If at the end vec.current == vec.start <-> value contains only 0:
// set vec.end to vec.current
// else
// set vec.end to vec.current <-> the last assigned digit
t_int_vector	ft_strtoa(const char *str)
{
	t_int_vector	res_vec;

	res_vec.start = malloc(ft_strlen(str) * sizeof(int));
	if (res_vec.start == NULL)
	{
		errno = ENOMEM;
		return (res_vec);
	}
	res_vec.current = res_vec.start;
	while (*str == ' ' || (*str >= '\t' & *str <= '\r'))
		str++;
	while (*str == '+')
		str++;
	while (*str == '0')
		*res_vec.current = ft_ctoi(*str++);
	while (*str >= '0' && *str <= '9')
		*((res_vec.current)++) = ft_ctoi(*(str++));
	if (res_vec.start == res_vec.current)
		res_vec.end = res_vec.current;
	else
		res_vec.end = res_vec.current - 1;
	return (res_vec);
}

char	*make_key(t_int_vector value, bool fill_zeros, bool use_current,
		size_t n)
{
	char	*str;
	char	*start;

	if (n == 0)
		return (NULL);
	str = malloc(n * sizeof(char));
	if (str == NULL)
		return (NULL);
	start = str;
	if (use_current)
		*str++ = ft_itoc(*(value.current++));
	else
		*str++ = ft_itoc(1);
	n--;
	while (n)
	{
		if (fill_zeros)
			*str++ = ft_itoc(0);
		else
			*str++ = ft_itoc(*(value.current++));
		n--;
	}
	return (start);
}

void	decide_and_show(t_dict *dict_ptr, t_int_vector *value_ptr)
{
	t_entry			*curr_entry;
	char			*key;
	t_dict			dict;
	t_int_vector	value;

	dict = *dict_ptr;
	value = *value_ptr;
	if ((value.end - value.current) % 3 == 1)
	{
		if (*value.current == 1)
		{
			key = make_key(value, false, true, 2);
			curr_entry = get_key_entry(dict, key, 2);
			free(key);
			ft_putstrn(curr_entry->value, curr_entry->value_len);
			ft_putchar(' ');
			value.current++;
		}
		else
		{
			key = make_key(value, true, true, 2);
			curr_entry = get_key_entry(dict, key, 2);
			free(key);
			ft_putstrn(curr_entry->value, curr_entry->value_len);
			ft_putchar(' ');
		}
		return ;
	}
	if (*value.current != 0)
	{
		key = make_key(value, false, true, 1);
		curr_entry = get_key_entry(dict, key, 1);
		free(key);
		ft_putstrn(curr_entry->value, curr_entry->value_len);
		ft_putchar(' ');
	}
	key = make_key(value, true, false, (value.end - value.current) + 1);
	curr_entry = get_key_entry(dict, key, (value.end - value.current) + 1);
	free(key);
	ft_putstrn(curr_entry->value, curr_entry->value_len);
	ft_putchar(' ');
}

// show_value_for_dict
void	show_value_for_dict(t_int_vector value, t_dict dict)
{
	t_entry	*curr_entry;
	char	*key;

	sort_dict(dict);
	value.current = value.start;
	if (value.start == value.end)
	{
		key = make_key(value, false, true, 1);
		curr_entry = get_key_entry(dict, key, 1);
		free(key);
		ft_putstrn(curr_entry->value, curr_entry->value_len);
		return ;
	}
	while ((unsigned long)value.current <= (unsigned long)value.end)
	{
		decide_and_show(&dict, &value);
		value.current++;
	}
	free(dict.entries);
}
