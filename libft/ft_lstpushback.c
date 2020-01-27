/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:33:12 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/29 16:46:50 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list *beginlist, t_list *new_elem)
{
	t_list	*temp;

	temp = beginlist;
	while (temp->next)
		temp = temp->next;
	temp->next = new_elem;
}
