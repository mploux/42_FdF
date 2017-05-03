/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:28:18 by mploux            #+#    #+#             */
/*   Updated: 2016/11/07 16:28:39 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	long	nb;
	int		length;

	length = 0;
	nb = n;
	if (nb < 0)
	{
		length = 1;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		length++;
	}
	return (length);
}
