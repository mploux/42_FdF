/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:27:37 by mploux            #+#    #+#             */
/*   Updated: 2016/12/13 13:36:29 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_vec3		vec3(double x, double y, double z)
{
	t_vec3 v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3		mat4_mul_vec3(t_mat4 a, t_vec3 b)
{
	t_vec3 result;

	result.x = a.m[0] * b.x + a.m[1] * b.y + a.m[2] * b.z + a.m[3];
	result.y = a.m[4] * b.x + a.m[5] * b.y + a.m[6] * b.z + a.m[7];
	result.z = a.m[8] * b.x + a.m[9] * b.y + a.m[10] * b.z + a.m[11];
	return (result);
}

t_vec3		vec3_add(t_vec3 *a, t_vec3 b)
{
	a->x += b.x;
	a->y += b.y;
	a->z += b.z;
	return (*a);
}
