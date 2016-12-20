/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:27:50 by mploux            #+#    #+#             */
/*   Updated: 2016/12/13 16:26:54 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <math.h>

# define ABS(x) (x < 0 ? -(x) : x)
# define DTR(angle) (angle * M_PI / 180)
# define LERP(a, b, n) (a + (b - a) * n)

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

typedef struct	s_mat4
{
	double		m[16];
}				t_mat4;

double			clamp(double a, double min, double max);
int				balance(int min, int max, int v);
t_vec2			vec2(double x, double y);
t_vec3			vec3(double x, double y, double z);
t_vec3			vec3_add(t_vec3 *a, t_vec3 b);
t_vec3			mat4_mul_vec3(t_mat4 a, t_vec3 b);
t_vec4			vec4(double x, double y, double z, double w);
t_vec4			vec2_2(t_vec2 a, t_vec2 b);
t_vec4			mat4_mul_vec4(t_mat4 a, t_vec4 b);
t_mat4			mat4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d);
t_mat4			mat4_identity();
t_mat4			mat4_mul(t_mat4 a, t_mat4 b);
t_mat4			mat4_translate(t_vec3 v);
t_mat4			mat4_rotate(t_vec3 axis, double angle);
t_mat4			mat4_rotate_xyz(double rx, double ry, double rz);
t_mat4			mat4_scale(t_vec3 v);
t_mat4			mat4_ortho(t_vec2 w, t_vec2 h, t_vec2 d);
t_mat4			mat4_persp(double fov, double aspect, double near, double far);
t_mat4			mat4_screen_space(double h_width, double h_height);

#endif
