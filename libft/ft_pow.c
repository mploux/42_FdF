/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:50:10 by mploux            #+#    #+#             */
/*   Updated: 2016/12/12 11:50:20 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_iterative_power(int nb, int power)
{
	int i;
	int tmp_nb;

	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	i = 0;
	tmp_nb = nb;
	while (i++ < power - 1)
		nb *= tmp_nb;
	return (nb);
}
