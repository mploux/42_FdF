/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:44:38 by mploux            #+#    #+#             */
/*   Updated: 2016/12/12 15:11:58 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_mat4		mat4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d)
{
	t_mat4	m;

	m.m[0] = a.x;
	m.m[1] = a.y;
	m.m[2] = a.z;
	m.m[3] = a.w;
	m.m[4] = b.x;
	m.m[5] = b.y;
	m.m[6] = b.z;
	m.m[7] = b.w;
	m.m[8] = c.x;
	m.m[9] = c.y;
	m.m[10] = c.z;
	m.m[11] = c.w;
	m.m[12] = d.x;
	m.m[13] = d.y;
	m.m[14] = d.z;
	m.m[15] = d.w;
	return (m);
}

t_mat4		mat4_identity(void)
{
	t_mat4	m;
	int		i;

	i = 0;
	while (i < 16)
		m.m[i++] = 0;
	m.m[0] = 1;
	m.m[5] = 1;
	m.m[10] = 1;
	m.m[15] = 1;
	return (m);
}

t_mat4		mat4_mul(t_mat4 a, t_mat4 b)
{
	t_mat4	r;
	int		i;
	int		j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			r.m[i + j * 4] = a.m[0 + j * 4] * b.m[i + 0 * 4] +
								a.m[1 + j * 4] * b.m[i + 1 * 4] +
								a.m[2 + j * 4] * b.m[i + 2 * 4] +
								a.m[3 + j * 4] * b.m[i + 3 * 4];
			i++;
		}
		j++;
	}
	return (r);
}
