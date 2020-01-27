/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 21:56:06 by gdrion            #+#    #+#             */
/*   Updated: 2018/06/29 17:06:12 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	void	*tab;
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL || !content_size)
	{
		new->content = NULL;
		new->next = NULL;
		new->content_size = 0;
		return (new);
	}
	if (!(tab = malloc(content_size)))
		return (NULL);
	new->content = ft_memcpy(tab, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
