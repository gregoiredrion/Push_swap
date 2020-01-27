/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:53:12 by gdrion            #+#    #+#             */
/*   Updated: 2019/05/21 02:53:13 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

static int	free_str(const int fd, char **str, int ret)
{
	ft_strdel(&str[fd]);
	return (ret);
}

static int	get_the_line(const int fd, char **str, char **line, char *tmp)
{
	char	*ptr_bn;
	char	*ptr_b0;

	ptr_bn = ft_strchr(str[fd], '\n');
	ptr_b0 = ft_strchr(str[fd], '\0');
	if (ptr_bn != NULL)
	{
		if (!(*line = ft_strsub(str[fd], 0, ptr_bn - str[fd])))
			return (free_str(fd, str, -1));
		if (!(tmp = ft_strdup(ptr_bn + 1)))
			return (free_str(fd, str, -1));
		ft_strdel(&str[fd]);
		str[fd] = tmp;
	}
	else if (ptr_b0 != NULL)
	{
		if (!(*line = ft_strsub(str[fd], 0, ptr_b0 - str[fd])))
			return (free_str(fd, str, -1));
		ft_strdel(&str[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX + 1];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		if (!(tmp = ft_strjoin(str[fd], buf)))
			return (free_str(fd, str, -1));
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	if (ret == -1)
		return (-1);
	if ((ret == 0 && str[fd] == NULL) || ft_strlen(str[fd]) == 0)
		return (free_str(fd, str, 0));
	return (get_the_line(fd, str, line, tmp));
}
