# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 13:27:11 by agabasov          #+#    #+#              #
#    Updated: 2023/06/24 13:27:16 by agabasov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
CFLAGS = -Wall -Wextra
SRCS = main.c\
 file_lib.c\
 clio_lib.c\
 string_lib.c\
 temp_lib.c\
 map_lib.c\
 vec_lib.c\
 ft_memcpy.c\
 lib.c\
 map_lib.c\
 spec_lib.c\
 solver.c\
 map_lib2.c

HEADERS = lib.h
FILES = $(SRCS) $(HEADERS)


all: $(NAME)


debug: CFLAGS += -g
debug: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME): $(SRCS:.c=.o)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(SRCS:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

norm:
	c_formatter_42 $(FILES)

norm_check:
	norminette $(FILES)

renorm:	norm norm_check

.PHONY: all
