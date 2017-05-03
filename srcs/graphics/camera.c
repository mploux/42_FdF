/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:14:52 by mploux            #+#    #+#             */
/*   Updated: 2017/05/03 16:58:11 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphics.h"
#include "maths.h"

t_camera	*new_camera(t_data *data, t_vec2 rot, double zoom)
{
	t_camera *cam;

	if (!(cam = (t_camera *)ft_memalloc(sizeof(t_camera))))
		error("malloc error !");
	cam->proj = mat4_identity();
	cam->z_near = 5;
	cam->z_far = 1000;
	cam->aspect = (double)data->win->w / (double)data->win->h;
	cam->rot = rot;
	cam->scale = vec3(1, 0.1, 1);
	cam->zoom = zoom;
	cam->trs = mat4_identity();
	cam->apos = vec2(0, 0);
	cam->arot = rot;
	cam->ascale = vec2(1, 1);
	cam->azoom = zoom;
	return (cam);
}

void		cam_input(t_input *input, t_camera *cam)
{
	(void) input;
	(void) cam;
	if (get_key(input, SDL_SCANCODE_W))
		cam->apos.y++;
	if (get_key(input, SDL_SCANCODE_S))
		cam->apos.y--;
	if (get_key(input, SDL_SCANCODE_A))
		cam->apos.x++;
	if (get_key(input, SDL_SCANCODE_D))
		cam->apos.x--;
	if (get_key(input, SDL_SCANCODE_UP))
		cam->arot.x--;
	if (get_key(input, SDL_SCANCODE_DOWN))
		cam->arot.x++;
	if (get_key(input, SDL_SCANCODE_LEFT))
		cam->arot.y--;
	if (get_key(input, SDL_SCANCODE_RIGHT))
		cam->arot.y++;
	if (get_key(input, SDL_SCANCODE_PAGEUP))
		cam->ascale.y += 0.1;
	if (get_key(input, SDL_SCANCODE_PAGEDOWN))
		cam->ascale.y -= 0.1;
	if (get_key(input, SDL_SCANCODE_KP_PLUS))
		cam->azoom--;
	if (get_key(input, SDL_SCANCODE_KP_MINUS))
		cam->azoom++;
}

void		cam_update(t_camera *cam)
{
	if (cam->ascale.y == 0)
		cam->ascale.y = 0.001;
	cam->pos.x = cam->apos.x * 0.5;
	cam->pos.y = cam->apos.y * 0.5;
	cam->rot.x = cam->arot.x;
	cam->rot.y = cam->arot.y;
	cam->scale.y = cam->ascale.y * 0.5;
	cam->zoom = cam->azoom;
}

t_mat4		cam_transform(t_camera *cam, t_mesh *mesh)
{
	t_mat4	m[4];
	t_vec3	pos;

	pos = vec3(-mesh->w / 2 + cam->pos.x,
				-(mesh->max_y * cam->scale.y) / 2,
				-mesh->h / 2 + cam->pos.y);
	m[0] = mat4_rotate_xyz(cam->rot.x, cam->rot.y, 0);
	m[1] = mat4_mul(m[0], mat4_translate(pos));
	m[2] = mat4_mul(mat4_translate(vec3(0, 0, -cam->zoom)), m[1]);
	return (mat4_mul(m[2], mat4_scale(cam->scale)));
}

t_mat4		cam_projection(t_data *data, t_camera *cam)
{
	if (data->projection)
		cam->proj = mat4_persp(70.0, cam->aspect, cam->z_near, cam->z_far);
	else
		cam->proj = mat4_ortho(vec2(-cam->zoom * cam->aspect,
									cam->zoom * cam->aspect),
								vec2(-cam->zoom, cam->zoom),
								vec2(-cam->zoom, cam->zoom));
	return (cam->proj);
}
