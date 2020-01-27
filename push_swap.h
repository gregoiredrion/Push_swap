/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:15:37 by gdrion            #+#    #+#             */
/*   Updated: 2019/06/17 21:19:33 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_pile
{
	int				data;
	struct s_pile	*next;
}				t_pile;

typedef struct	s_hold
{
	t_pile	*a;
	t_pile	*b;
	int		max;
	char	*com;
	int		index;
	FILE	*fd;
}				t_hold;
/*
** stock_pile.c
*/
int				stock_pile(t_hold *hold, char **av);
void			free_hold(t_hold *hold);
void			free_pile(t_pile *a);
t_hold			*create_hold(void);
/*
** checker_reader.c
*/
int				checker_reader(t_hold *hold);
int				do_ops(char *op, t_hold *h);
/*
** oper1.c
*/
t_pile			*sa_sb(t_pile *a, t_hold *h);
void			ss(t_hold *h, char c);
void			pb(t_hold *h);
void			pa(t_hold *h);
/*
** oper2.c
*/
t_pile			*rra_rrb(t_pile *pile, t_hold *h);
void			rrr(t_hold *hold, char c);
t_pile			*ra_rb(t_pile *pile, t_hold *h);
void			rr(t_hold *h, char c);
/*
** error_checker.c
*/
int				free_error(t_hold *hold);
int				sorted(t_pile *pile);
t_hold			*check_errors(char **av, int ac, int pw);
/*
** add_and_del_commands.c
*/
int				do_and_add(char *op, t_hold *h);
void			del_command(t_hold *h);
/*
** small_sort.c
*/
int				sort_small(t_hold *h, int count, int max, int old_op);
/*
** big_sort.c && spin_the_wheel
*/
int				spin_the_wheel(t_pile *pile, int nb, int max);
int				pile_len(t_pile *b);
int				big_sort(t_hold *h);
int				op_by_count(t_hold *h, char *op, int count);
int				fill_a(t_hold *a, int len_b);
/*
**	copy_hold.c
*/
t_hold			*copy_info(t_hold *h);
/*
**	count_before_push
*/
int				get_best_pos(t_hold *h, t_pile *pile, int len_b, int len_a);
/*
** sort_int_tab.c
*/
void			quicksort(int *tab, int start, int end);
/*
**	duplicates.c
*/
int				ft_error_pusw(char *str, intmax_t nb);
int				duplicates(char **av, t_hold *h, int ac, int pw);
/*
**	fd_stock.c
*/
void			data_fd(t_pile *a, FILE *fd);
void			ops_data_fd(char *ops, t_pile *a, FILE *fd);

#endif
