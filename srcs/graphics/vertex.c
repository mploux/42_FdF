/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 00:15:46 by mploux            #+#    #+#             */
/*   Updated: 2016/12/14 21:29:51 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_vertex		vertex(t_data *data, t_vec3 pos, int color)
{
	t_vertex result;

	result.data = data;
	result.pos = vec4(pos.x, pos.y, pos.z, 1);
	result.col = color;
	return (result);
}

static t_vec4	p_div(t_vec4 v)
{
	t_vec4 result;

	result.x = v.x / v.w;
	result.y = v.y / v.w;
	result.z = v.z / v.w;
	result.w = v.w;
	return (result);
}

int				in_view_frustum(t_vertex *v)
{
	return (v->s_pos.x >= 0 ||
			v->s_pos.y >= 0 ||
			v->s_pos.x < v->data->win->w ||
			v->s_pos.y < v->data->win->h);
}

int				vertex_transform(t_data *data, t_vertex *vert, t_mat4 trs)
{
	t_vec4	pos;
	t_vec4	tpos;
	t_mat4	proj;
	t_mat4	screen_space;

	screen_space = data->screen_space;
	tpos = mat4_mul_vec4(trs, vert->pos);
	proj = mat4_mul(cam_projection(data, data->camera), trs);
	pos = p_div(mat4_mul_vec4(screen_space, mat4_mul_vec4(proj, vert->pos)));
	if (data->projection == 0)
		pos.w = ((tpos.x * tpos.x) + (tpos.y * tpos.y) + (tpos.z * tpos.z));
	pos.x = clamp(pos.x, -1, data->win->w);
	pos.y = clamp(pos.y, -1, data->win->h);
	pos.w = clamp(pos.w, 3, 1000);
	vert->s_pos = pos;
	vert->sc = vec2(pos.x, pos.y);
	return (1);
}
