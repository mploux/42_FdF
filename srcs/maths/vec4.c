/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:27:37 by mploux            #+#    #+#             */
/*   Updated: 2016/12/03 22:14:08 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_vec4		vec4(double x, double y, double z, double w)
{
	t_vec4 v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_vec4		vec2_2(t_vec2 a, t_vec2 b)
{
	t_vec4 v;

	v.x = a.x;
	v.y = a.y;
	v.z = b.x;
	v.w = b.y;
	return (v);
}

t_vec4		mat4_mul_vec4(t_mat4 a, t_vec4 b)
{
	t_vec4 result;

	result.x = a.m[0] * b.x + a.m[1] * b.y + a.m[2] * b.z + a.m[3] * b.w;
	result.y = a.m[4] * b.x + a.m[5] * b.y + a.m[6] * b.z + a.m[7] * b.w;
	result.z = a.m[8] * b.x + a.m[9] * b.y + a.m[10] * b.z + a.m[11] * b.w;
	result.w = a.m[12] * b.x + a.m[13] * b.y + a.m[14] * b.z + a.m[15] * b.w;
	return (result);
}
