/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:56:00 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/25 15:58:07 by sgiazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// create dictionnary
// char *str have the string from dictionnary
// loop create lines (i < dict.size)
// "str +=" move position of values to send get_entry(str)
t_dict	get_dict(char *str)
{
	t_dict	dict;
	size_t	i;

	dict.size = ft_count_char(str, '\n');
	dict.entries = malloc(dict.size * sizeof(t_entry));
	if (dict.entries == NULL)
	{
		errno = ENOMEM;
		return (dict);
	}
	i = 0;
	while (i < dict.size)
	{
		dict.entries[i] = get_entry(str);
		str += dict.entries[i].key_len + dict.entries[i].value_len
			+ dict.entries[i].pad;
		i++;
	}
	return (dict);
}

// sorts a dict by entry key length and lexicographically
// Check if in need of a swap
void	sort_dict(t_dict dict)
{
	size_t	i;

	i = 1;
	while (i < dict.size)
	{
		if ((dict.entries[i].key_len < dict.entries[i - 1].key_len)
			|| ((dict.entries[i].key_len == dict.entries[i - 1].key_len)
				&& (ft_strncmp(dict.entries[i].key, dict.entries[i - 1].key,
						dict.entries[i].key_len) < 0)))
		{
			swap_entries(&dict.entries[i], &dict.entries[i - 1]);
			i = 0;
		}
		i++;
	}
}

// Search key in dictionnary
// Return it
t_entry	*get_key_entry(t_dict dict, char *key, size_t key_length)
{
	size_t	i;

	i = 0;
	while (i < dict.size)
	{
		if ((key_length == dict.entries[i].key_len)
			&& (ft_strncmp(dict.entries[i].key, key, key_length) == 0))
			return (&dict.entries[i]);
		i++;
	}
	return (NULL);
}

void	show_dict(t_dict dict)
{
	size_t	i;

	i = 0;
	while (i < dict.size)
		show_entry(dict.entries[i++]);
}
