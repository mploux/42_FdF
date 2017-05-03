/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 03:29:55 by mploux            #+#    #+#             */
/*   Updated: 2016/12/15 15:12:45 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_mesh		*new_mesh(t_data *data)
{
	t_mesh *mesh;

	if (!(mesh = (t_mesh *)ft_memalloc(sizeof(t_mesh))))
		error("malloc error");
	mesh->data = data;
	mesh->vertices = NULL;
	mesh->indices = NULL;
	mesh->v_list = NULL;
	return (mesh);
}

void		mesh_create_indices(t_mesh *m)
{
	int i;
	int index;
	int offs;
	int size;

	size = (m->w - 1) * (m->h - 1);
	if (!(m->indices = ft_memalloc(sizeof(int) * (size * 6))))
		error("malloc error !");
	i = -1;
	offs = 0;
	while ((i - offs) < size)
	{
		++i;
		index = (i - offs) * 6;
		if (i % m->w == m->w - 1)
			offs++;
		if (index >= size * 6)
			break ;
		m->indices[index + 0] = i;
		m->indices[index + 1] = i + 1;
		m->indices[index + 2] = i + m->w + 1;
		m->indices[index + 3] = i;
		m->indices[index + 4] = i + m->w + 1;
		m->indices[index + 5] = i + m->w;
	}
}

void		mesh_draw_filled(t_mesh *m, t_mat4 trs)
{
	int			i;
	int			j;
	int			size;
	t_vertex	v[6];
	t_triangle	tris[2];

	size = (m->w - 1) * (m->h - 1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 6)
			v[j] = m->vertices[m->indices[i * 6 + j]];
		tris[0] = triangle(v[0], v[1], v[2]);
		tris[1] = triangle(v[3], v[4], v[5]);
		draw_triangle(m->data, tris[0], trs);
		draw_triangle(m->data, tris[1], trs);
	}
}

void		mesh_draw_wireframe(t_mesh *m, t_mat4 trs)
{
	int			i;
	int			j;
	int			size;
	t_vertex	v[6];

	size = (m->w - 1) * (m->h - 1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 6)
		{
			v[j] = m->vertices[m->indices[i * 6 + j]];
			vertex_transform(m->data, &(v[j]), trs);
		}
		draw_line(m->data, v[0], v[1], vec2(v[0].col, v[1].col));
		draw_line(m->data, v[0], v[5], vec2(v[0].col, v[5].col));
		if (i % (m->w - 1) == m->w - 2)
			draw_line(m->data, v[1], v[4], vec2(v[1].col, v[4].col));
		if (i / (m->w - 1) == m->h - 2)
			draw_line(m->data, v[5], v[4], vec2(v[5].col, v[4].col));
	}
}
