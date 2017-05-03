/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 07:33:27 by mploux            #+#    #+#             */
/*   Updated: 2016/12/14 20:42:29 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstclear(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (*list)
	{
		tmp = (*list)->next;
		ft_memdel(&((*list)->content));
		ft_memdel((void **)list);
		*list = tmp;
	}
}
