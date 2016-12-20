/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 21:25:52 by mploux            #+#    #+#             */
/*   Updated: 2016/12/14 21:39:36 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	read_line(const int fd, char **before, char **after)
{
	char	*buff;
	char	nbuff[BUFF_SIZE + 1];
	int		ret;
	int		cptr;
	char	*tmp;

	cptr = 0;
	buff = NULL;
	while ((ret = read(fd, nbuff, BUFF_SIZE)) > 0)
	{
		nbuff[ret] = 0;
		cptr += ret;
		buff = ft_realloc(buff, cptr + 1);
		ft_strncat(buff, nbuff, ret);
		if ((tmp = ft_strchr(buff, '\n')))
		{
			*after = ft_strdup(tmp + 1);
			*before = ft_strsub(buff, 0, tmp - buff);
			ft_strdel(&buff);
			return (ret);
		}
	}
	if (ret == 0 && ft_strlen(buff) > 0)
		return ((*before = buff) ? 1 : 1);
	return (ret);
}

static int	find_line_in_rest(char **rest, char **line)
{
	char *tmp;
	char *new_rest;

	if (rest && *rest && (tmp = ft_strchr(*rest, '\n')))
	{
		*line = ft_strsub(*rest, 0, tmp - (*rest));
		new_rest = ft_strdup(tmp + 1);
		ft_strdel(rest);
		*rest = new_rest;
		return (1);
	}
	return (0);
}

static int	get_fd_line(t_gnl *gnl, char **line)
{
	int			ret;
	char		*before;
	char		*after;

	if ((ret = find_line_in_rest(&gnl->rest, line)))
		return (ret);
	if ((ret = read_line(gnl->fd, &before, &after)) == 0)
	{
		if ((ret = (gnl->rest && ft_strlen(gnl->rest) > 0)))
			*line = ft_strdup(gnl->rest);
		if (gnl->rest && gnl->rest[0] != 0)
			ft_strdel(&gnl->rest);
		return (ret ? 1 : 0);
	}
	else if (ret < 0)
		return (-1);
	*line = ft_strjoin(gnl->rest, before);
	ft_strdel(&gnl->rest);
	ft_strdel(&before);
	return ((gnl->rest = after) ? 1 : 1);
}

static void	rm_from_list(t_gnl **gnl, t_gnl *elem)
{
	t_gnl	*tmp;

	tmp = *gnl;
	if (elem == *gnl)
	{
		*gnl = (*gnl)->next;
		free(elem->rest);
		free(elem);
		return ;
	}
	while (tmp && tmp->next && tmp->next != elem)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	free(elem);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*elem;
	int				ret;

	elem = gnl;
	while (elem && elem->fd != fd)
		elem = elem->next;
	if (!elem)
	{
		if (!(elem = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
			return (-1);
		elem->fd = fd;
		elem->rest = NULL;
		elem->next = gnl;
		gnl = elem;
	}
	if (!(ret = get_fd_line(elem, line)))
		rm_from_list(&gnl, elem);
	return (ret);
}
