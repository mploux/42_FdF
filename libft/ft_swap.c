/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 03:04:58 by mploux            #+#    #+#             */
/*   Updated: 2016/12/03 03:27:07 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	size_t			i;
	unsigned char	tmp;

	i = -1;
	while (++i < size)
	{
		tmp = ((unsigned char *)a)[i];
		((unsigned char *)a)[i] = ((unsigned char *)b)[i];
		((unsigned char *)b)[i] = tmp;
	}
}
