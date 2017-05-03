/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:14:32 by mploux            #+#    #+#             */
/*   Updated: 2016/11/26 23:36:51 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_fill_itoa(int i, int n, char *str)
{
	long nb;

	nb = n;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	else
		nb = n;
	if (nb > 0)
	{
		ft_fill_itoa(i - 1, nb / 10, str);
		str[i] = ('0' + (nb % 10));
	}
}

char			*ft_itoa(int n)
{
	int		length;
	char	*result;

	if (n == 0)
	{
		length = 1;
		if (!(result = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		result[0] = '0';
		result[1] = 0;
		return (result);
	}
	length = ft_nbrlen(n);
	if (!(result = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	ft_fill_itoa(length - 1, n, result);
	result[length] = 0;
	return (result);
}
