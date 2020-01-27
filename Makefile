# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdrion <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 16:18:33 by gdrion            #+#    #+#              #
#    Updated: 2019/06/07 18:34:29 by gdrion           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 =	push_swap
NAME2 =	checker
SRC1 = push_swap.c stock_pile.c oper1.c oper2.c copy_hold.c add_and_del_commands.c small_sort.c error_checker.c checker_reader.c big_sort.c spin_the_wheel.c count_before_push.c duplicates.c fd_stock.c sort_int_tab.c
SRC2 = 	checker.c oper1.c oper2.c checker_reader.c error_checker.c stock_pile.c gnl/get_next_line.c duplicates.c sort_int_tab.c fd_stock.c
OBJ1 =	$(SRC1:.c=.o)
OBJ2 =	$(SRC2:.c=.o)
CC   = 	gcc

all : lib $(NAME1) $(NAME2)

lib:
	@make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -I./libft -Llibft -lft -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -I./libft -Llibft -lft -o $(NAME2)

clean:
	@make clean -C libft
	@rm -rf $(OBJ1) $(OBJ2) get_next_line.o

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME1) $(NAME2) __pycache__ infos.txt *.dSYM

re: fclean all
