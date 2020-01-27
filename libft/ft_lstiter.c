/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:11:07 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/26 15:16:38 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	t_list	*temp;
	t_list	*nextlst;

	temp = lst;
	while (temp)
	{
		nextlst = temp->next;
		f(temp);
		temp = nextlst;
	}
}
