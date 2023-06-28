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

/*
  |----------------|---|......
  |....o...........|...|......
  |........A...o...|.B.|......
  |----------------a---b......
  |....o...........|...|......
  |........C......o|.D.|......
  |................|...|......
  |------o---------c---do.....
   ..o.......o................

  |----------------|---|......
  |....o...A.......|.B.|......
  |------------o---a---b......
  |................|...|......
  |....o...........|...|......
  |........C......o|.D.|......
  |................|...|......
  |------o---------c---do.....
   ..o.......o................
			a.x = c.x | b.x = d.x
	|-------------|----|---
	|             |    |  |
	|             |    |  |
	|_____________a____b  |  a.y = b.y
	|             |    |  |
	|             |    |  |
	|_____________c____d  |  d.y = c.y
	|_____________________|
				d.x = b.x
	-----------------------
	|             |       |
	|             |       |
	|_____________b       |  b.y
	|             |       |
	|             |       |
	|_____________d       |  d.y
	|_____________________|
					c.x  d.x
	-----------------------
	|             |    |  |
	|             |    |  |
	|_____________c____d  |  d.y = c.y
	|                     |
	|                     |
	|                     |
	|_____________________|
		d.x
	-----------------------
	|                     |
	|----|                |
	|    |                |
	|----d                |  d.y
	|                     |
	|                     |
	|_____________________|
*/
typedef struct s_point
{
	int						x;
	int						y;
}							t_point;

typedef struct s_int_vector
{
	int						*start;
	int						*current;
	int						*end;
}							t_int_vector;

typedef struct s_char_vector
{
	const char				*start;
	char					*current;
	char					*end;
}							t_char_vector;

typedef struct s_specification
{
	bool					valid;
	char					empty;
	char					obstacle;
	char					full;
	size_t					number_of_lines;
}							t_specification;

typedef struct s_map
{
	t_specification			specification;
	t_char_vector			*start;
	t_char_vector			*current;
	t_char_vector			*end;
}							t_map;

typedef struct s_linked_list
{
	void					*data;
	struct s_linked_list	*next;
}							t_linked_list;

typedef struct s_solution
{
	int						size;
	t_point					d;
}							t_solution;

typedef struct s_solver_spec
{
	t_point					a;
	t_point					b;
	t_point					c;
	t_point					d;
}							t_solver_spec;

size_t						ft_strlen(const char *str);

void						ft_putchar(char c);

void						ft_putstr(const char *str);

void						ft_putstrn(const char *str, size_t n);

size_t						strlen_until_char(const char *str, char c);

size_t						char_vec_length(t_char_vector vec);

void						ft_putnbr_aux(int n);

void						ft_putnbr(int nb);

size_t						ft_count_char(const char *str, char chr);

void						ft_puterr(char *error_detail);

int							ft_strncmp(char *s1, char *s2, unsigned int n);

size_t						int_vec_length(t_int_vector vec);

int							ft_ctoi(char c);

// Switch int to char in ASCII (+ 48)
char						ft_itoc(int i);

size_t						strnlen_until_char(const char *str, char c,
								size_t n);

size_t						repeat_char_n(const char *str, char c, size_t n);

size_t						get_file_size(int fd);

bool						check_read_file(int fd);

bool						check_open_file(int fd);

char						*get_file_string(int fd, size_t file_size);

void						*ft_memcpy(void *dst0, const void *src0,
								size_t size);

void						get_map_obstacle_count(int x, int y,
								const char **map_string);

void						ft_putsize(size_t size);

int							get_best_size(int *const *arr, t_point d);

int							get_obstacles(int *const *arr, t_solver_spec spec);

int							get_size(t_solver_spec solver_spec);

// Switch int to char in ASCII (+ 48)
char						ft_stoc(size_t size);

unsigned long				ft_power(unsigned int b, unsigned int e);

t_specification				make_specification(const char *map_string);

void						show_spec(t_specification specification);

char						*get_stdin_string(void);

void						print_map(int x, int y,
								const char *const *map_string);

void						preset_obstacles(int x, int y,
								const char *const *map_string,
								int **obstacle_matrix);

void						set_all_obstacle_count(int x, int y,
								int **obstacle_matrix);

t_solution					get_best_solution(int x, int y, int **arr);

void						show_solution(int x, int y,
								const char *const *map_string,
								t_solution solution);
#endif
