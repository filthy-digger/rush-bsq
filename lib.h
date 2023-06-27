/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:21:43 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/24 18:47:27 by sgiazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <assert.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_entry
{
	char			*value;
	char			*key;
	size_t			key_len;
	size_t			value_len;
	size_t			pad;
}					t_entry;

typedef struct s_dict
{
	t_entry			*entries;
	size_t			size;
}					t_dict;

typedef struct s_int_vector
{
	int				*start;
	int				*current;
	int				*end;
}					t_int_vector;

typedef struct s_char_vector
{
	char			*start;
	char			*current;
	char			*end;
}					t_char_vector;

typedef struct s_specification
{
	char			empty;
	char			obstacle;
	char			full;
	size_t			number_of_lines;
}					t_specification;

typedef struct s_map
{
	t_specification	specification;
	t_char_vector	*start;
	t_char_vector	*current;
	t_char_vector	*end;
}					t_map;

size_t				ft_strlen(const char *str);

void				ft_putchar(char c);

void				ft_putstr(const char *str);

void				ft_putstrn(const char *str, size_t n);

// ft_strtoa takes:
// a null-terminated string - "str"
//
// returns:
// NULL if malloc failed
// the integer array decoded like atoi from "str"
t_int_vector		ft_strtoa(t_char_vector str);

size_t				strlen_until_char(const char *str, char c);

size_t				char_vec_length(t_char_vector vec);

// get_entry
// takes:
// a non-empty string - "str"
// returns:
// an s_entry struct with data parsed from "str"
//
// format of "str" is:
//[a number][0 to n spaces]:[0 to n spaces][any printable characters]\n
t_entry				get_entry(char *str);

void				show_entry(t_entry entry);

void				ft_putnbr_aux(int n);

void				ft_putnbr(int nb);

size_t				ft_count_char(char *str, char chr);

// get_dict
// takes:
// a non-empty string - "str"
// returns:
// an s_dict struct with data parsed from "str"
//
// format of "str" is lines formatted:
//[a number]:[any printable characters]\n
t_dict				get_dict(char *str);

void				show_dict(t_dict dict);

bool				check_value_arg(char *str);

void				ft_puterr(char *error_detail);

void				swap_entries(t_entry *e1, t_entry *e2);

void				sort_dict(t_dict dict);

int					ft_strncmp(char *s1, char *s2, unsigned int n);

size_t				int_vec_length(t_int_vector vec);

void				show_value_for_dict(t_int_vector value, t_dict dict);

int					ft_ctoi(char c);
char				ft_itoc(int i);

size_t				strnlen_until_char(const char *str, char c, size_t n);

size_t				repeat_char_n(const char *str, char c, size_t n);

size_t				get_file_size(int fd);

bool				check_read_file(int fd);

bool				check_open_file(int fd);

char				*get_file_string(int fd, size_t file_size);

void	*ft_memmove(void *dst0, const void *src0, size_t size);

void	*ft_memcpy(void *dst0, const void *src0, size_t size);

void get_map_obstacle_count(int x, int y, char map_string[y][x]);

void				ft_putsize(size_t size);

typedef struct s_point
{
	int x;
	int y;
} t_point;

int get_best_size(int *const *arr,t_point d);

int	get_obstacles(int *const *arr, t_point a, t_point b, t_point c, t_point d);

int	get_size(t_point a, t_point b, t_point c, t_point d);
#endif
