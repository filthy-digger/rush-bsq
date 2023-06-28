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
	int				x;
	int				y;
}					t_point;

typedef struct s_char_vector
{
	const char		*start;
	const char		*current;
	const char		*end;
}					t_char_vector;

typedef struct s_specification
{
	bool			valid;
	char			empty;
	char			obstacle;
	char			full;
	t_char_vector	first_line;
	int				number_of_lines;
	int				line_length;
}					t_map_spec;

typedef struct s_map
{
	bool			valid;
	t_map_spec		spec;
	const char		**lines;
}					t_map;

typedef struct s_solution
{
	int				size;
	t_point			d;
}					t_solution;

typedef struct s_solver_spec
{
	t_point			a;
	t_point			b;
	t_point			c;
	t_point			d;
}					t_solver_spec;

size_t				ft_strlen(const char *str);

void				ft_putchar(char c);

void				ft_putstr(const char *str);

void				ft_putstrn(const char *str, size_t n);

size_t				char_vec_length(t_char_vector vec);

void				ft_putnbr_aux(int n);

void				ft_putnbr(int nb);

size_t				ft_count_char(const char *str, char chr);

void				ft_puterr(char *error_detail);

int					ft_strncmp(char *s1, char *s2, unsigned int n);

int					ft_ctoi(char c);

// Switch int to char in ASCII (+ 48)
char				ft_itoc(int i);

size_t				strnlen_until_char(const char *str, char c, size_t n);

size_t				repeat_char_n(const char *str, char c, size_t n);

size_t				get_file_size(int fd);

bool				check_read_file(int fd);

bool				check_open_file(int fd);

char				*get_file_string(int fd, size_t file_size);

void				*ft_memcpy(void *dst0, const void *src0, size_t size);

void				get_map_obstacle_count(t_map map);

void				ft_putsize(size_t size);

int					get_best_size(int **arr, t_point d);

int					get_obstacles(int **arr, t_solver_spec spec);

int					get_size(t_solver_spec solver_spec);

// Switch int to char in ASCII (+ 48)
char				ft_stoc(size_t size);

unsigned long		ft_power(unsigned int b, unsigned int e);

t_map_spec			make_spec(const char *map_string);

void				show_spec(t_map_spec specification);

char				*get_stdin_string(void);

void				print_map(t_map map);

void				preset_obstacles(int **obstacle_matrix, t_map map);

void				set_all_obstacle_count(t_map map, int **obstacle_matrix);

t_solution			get_best_solution(int **arr, t_map map);

void				show_solution(t_solution solution, t_map map);

const char			*ft_strchr(const char *str, char c);

t_map				make_map(const char *map_string, bool isfile);
#endif
