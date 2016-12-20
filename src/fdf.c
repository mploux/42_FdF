/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:12:44 by mploux            #+#    #+#             */
/*   Updated: 2016/12/15 14:18:04 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "maths.h"
#include "graphics.h"
#include <stdlib.h>

int			create_fdf(t_data *data, const char *name, int width, int height)
{
	t_win		*win;

	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		error("malloc error !");
	if (!(data->mlx = mlx_init()))
		error("mlx error: mlx failed to load !");
	win->w = width;
	win->h = height;
	win->name = (char *)name;
	if (!(win->ctx = mlx_new_window(data->mlx, win->w, win->h, win->name)))
		error("mlx error: win failed to load !");
	data->win = win;
	data->input = new_input();
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
	mlx_put_image_to_window(data->mlx, data->win->ctx,
							data->framebuffer->ctx, 0, 0);
	draw_debug(data);
	clear_bitmap(data->framebuffer);
	clear_scanline(data, &data->scan_line);
	clear_zbuffer(data, 10000);
	return (1);
}

void		loop_fdf(t_data *data, t_mesh *mesh)
{
	data->mesh = mesh;
	mlx_hook(data->win->ctx, 2, (1L << 0), &key_hook, data);
	mlx_hook(data->win->ctx, 3, (1L << 1), &key_up_hook, data);
	mlx_loop_hook(data->mlx, &loop, data);
	mlx_loop(data->mlx);
}

void		exit_fdf(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win->ctx);
	mlx_destroy_image(data->mlx, data->framebuffer->ctx);
	free(data->camera);
	free(data->zbuffer);
	free(data->framebuffer);
	free(data->scan_line);
	free(data->input);
	free(data->mesh->vertices);
	free(data->mesh->indices);
	free(data->mesh);
	free(data);
	exit(0);
}
