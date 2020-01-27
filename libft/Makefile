# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdrion <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/19 12:25:30 by gdrion            #+#    #+#              #
#    Updated: 2019/02/12 15:48:58 by gdrion           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = $(shell find . -type f -name "*.c")
OBJ = $(SRC:.c=.o)
INC = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
	
clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
