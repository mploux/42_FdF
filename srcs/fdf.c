/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:12:44 by mploux            #+#    #+#             */
/*   Updated: 2017/05/03 16:30:43 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "maths.h"
#include "graphics.h"
#include <stdlib.h>

int			create_fdf(t_data *data, const char *name, int width, int height)
{
	if (!(data->win = (t_win *)ft_memalloc(sizeof(t_win))))
		error("malloc error !");
	new_sdl_display(data, name, width, height);
	init_inputs(data);
	data->win->w = width;
	data->win->h = height;
	data->win->name = (char *)name;
	data->aspect = (double)width / (double)height;
	data->screen_space = mat4_screen_space(width / 2, height / 2);
	data->scan_line = new_scanline(height);
	data->framebuffer = new_bitmap(data, width, height);
	data->zbuffer = new_zbuffer(width, height);
	data->filled_mode = 0;
	data->projection = 0;
	data->camera = new_camera(data, vec2(30, -45), 20);
	clear_zbuffer(data, 10000);
	return (1);
}

void		draw_debug(t_data *data)
{
	int y;

	y = data->win->h;
	draw_text(data, vec2(5, y - 25), 0xffffff, "Ecole 42 - FdF - mploux");
}

int			loop(t_data *data)
{
	t_mesh		*mesh;
	t_input		*input;
	t_camera	*cam;
	t_mat4		transformation;

	mesh = data->mesh;
	input = data->input;
	cam = data->camera;
	cam_input(input, cam);
	cam_update(cam);
	col_input(data, input);
	transformation = mat4_identity();
	transformation = cam_transform(cam, mesh);
	if (data->filled_mode)
		mesh_draw_filled(mesh, transformation);
	else
		mesh_draw_wireframe(mesh, transformation);
	draw_debug(data);
	bitmap_update(data->framebuffer);
	clear_bitmap(data->framebuffer);
	clear_scanline(data, &data->scan_line);
	clear_zbuffer(data, 10000);
	return (1);
}

void		loop_fdf(t_data *data, t_mesh *mesh)
{
	data->mesh = mesh;
	bitmap_update(data->framebuffer);
	sdl_loop(data, &loop);
}

void		exit_fdf(t_data *data)
{
	free(data->camera);
	free(data->zbuffer);
	free(data->framebuffer);
	free(data->scan_line);
	free(data->mesh->vertices);
	free(data->mesh->indices);
	free(data->mesh);
	free(data);
	exit(0);
}
