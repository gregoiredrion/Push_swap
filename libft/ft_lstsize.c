/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:47:02 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/29 16:56:44 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *beginlist)
{
	t_list	*temp;
	size_t	i;

	i = 0;
	temp = beginlist;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
