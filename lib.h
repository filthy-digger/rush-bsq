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
	int			x;
	int			y;
}				t_point;

typedef struct s_specification
{
	bool		valid;
	char		empty;
	char		obstacle;
	char		full;
	int			number_of_lines;
	int			line_length;
}				t_map_spec;

typedef struct s_map
{
	bool		valid;
	t_map_spec	spec;
	char		**lines;
}				t_map;

typedef struct s_solution
{
	int			size;
	t_point		d;
}				t_solution;

typedef struct s_solver_spec
{
	t_point		a;
	t_point		b;
	t_point		c;
	t_point		d;
}				t_solver_spec;

size_t			ft_strlen(const char *str);

void			ft_putchar(char c);

void			ft_putstr(const char *str);

void			ft_putnbr_aux(int n);

void			ft_putnbr(int nb);

void			ft_puterr(char *error_detail);

int				ft_ctoi(char c);

size_t			ft_get_fsize(int fd);

bool			ft_check_read(int fd);

bool			ft_check_open(int fd);

char			*ft_get_file(int fd, size_t file_size);

void			*ft_memcpy(void *dst0, const void *src0, size_t size);

void			ft_get_map_obstacle_count(t_map map);

void			ft_putsize(size_t size);

int				ft_get_best_size(int **arr, t_point d);

int				ft_get_obstacles(int **arr, t_solver_spec spec);

int				ft_get_size(t_solver_spec solver_spec);

// Switch int to char in ASCII (+ 48)
char			ft_stoc(size_t size);

int				ft_power(int b, unsigned int e);

t_map_spec		ft_make_spec(char *map_string);

void			ft_show_spec(t_map_spec specification);

char			*ft_get_stdin_string(void);

void			ft_print_map(t_map map);

void			ft_preset_obstacles(int **obstacle_matrix, t_map map);

void			ft_set_all_obstacle_count(t_map map, int **obstacle_matrix);

t_solution		ft_get_best_solution(int **arr, t_map map);

void			ft_show_solution(t_solution solution, t_map map);

char			*ft_strchr(char *str, char c);

t_map			ft_make_map(char *map_string);

void			map_solve(char *map_string);
#endif
