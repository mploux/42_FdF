/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:53:47 by mploux            #+#    #+#             */
/*   Updated: 2016/12/13 16:26:28 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double		clamp(double a, double min, double max)
{
	if (a < min)
		a = min;
	if (a > max)
		a = max;
	return (a);
}

int			balance(int min, int max, int v)
{
	int r;
	int diff;

	diff = (max - min);
	r = v % (max + diff);
	if (r > max)
		r = max - (r - diff);
	if (r < min)
		r = -r;
	return (r);
}
