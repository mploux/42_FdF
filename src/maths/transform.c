/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:03:44 by mploux            #+#    #+#             */
/*   Updated: 2016/12/12 15:12:17 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_mat4		mat4_translate(t_vec3 v)
{
	t_mat4 result;

	result = mat4_identity();
	result.m[3] = v.x;
	result.m[7] = v.y;
	result.m[11] = v.z;
	return (result);
}

t_mat4		mat4_rotate(t_vec3 axis, double angle)
{
	t_mat4	rx;
	t_mat4	ry;
	t_mat4	rz;
	double	rad;

	rad = DTR(angle);
	rx = mat4_identity();
	ry = mat4_identity();
	rz = mat4_identity();
	rx.m[5] = cos(rad * axis.x);
	rx.m[6] = -sin(rad * axis.x);
	rx.m[9] = sin(rad * axis.x);
	rx.m[10] = cos(rad * axis.x);
	ry.m[0] = cos(rad * axis.y);
	ry.m[2] = sin(rad * axis.y);
	ry.m[8] = -sin(rad * axis.y);
	ry.m[10] = cos(rad * axis.y);
	rz.m[0] = cos(rad * axis.z);
	rz.m[1] = -sin(rad * axis.z);
	rz.m[4] = sin(rad * axis.z);
	rz.m[5] = cos(rad * axis.z);
	return (mat4_mul(rx, mat4_mul(ry, rz)));
}

t_mat4		mat4_rotate_xyz(double rx, double ry, double rz)
{
	t_mat4	x;
	t_mat4	y;
	t_mat4	z;

	x = mat4_identity();
	y = mat4_identity();
	z = mat4_identity();
	x.m[5] = cos(DTR(rx));
	x.m[6] = -sin(DTR(rx));
	x.m[9] = sin(DTR(rx));
	x.m[10] = cos(DTR(rx));
	y.m[0] = cos(DTR(ry));
	y.m[2] = sin(DTR(ry));
	y.m[8] = -sin(DTR(ry));
	y.m[10] = cos(DTR(ry));
	z.m[0] = cos(DTR(rz));
	z.m[1] = -sin(DTR(rz));
	z.m[4] = sin(DTR(rz));
	return (mat4_mul(x, mat4_mul(y, z)));
}

t_mat4		mat4_scale(t_vec3 v)
{
	t_mat4 result;

	result = mat4_identity();
	result.m[0] = v.x;
	result.m[5] = v.y;
	result.m[10] = v.z;
	return (result);
}
