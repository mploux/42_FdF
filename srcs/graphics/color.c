/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:23:22 by mploux            #+#    #+#             */
/*   Updated: 2017/05/03 16:48:28 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphics.h"

int		col_lerp(int a, int b, double n)
{
	t_vec3 ca;
	t_vec3 cb;
	t_vec3 cl;

	ca.x = (int)((a & 0xff0000) >> 16);
	ca.y = (int)((a & 0xff00) >> 8);
	ca.z = (int)((a & 0xff));
	cb.x = (int)((b & 0xff0000) >> 16);
	cb.y = (int)((b & 0xff00) >> 8);
	cb.z = (int)((b & 0xff));
	cl.x = LERP(ca.x, cb.x, n);
	cl.y = LERP(ca.y, cb.y, n);
	cl.z = LERP(ca.z, cb.z, n);
	return ((int)cl.x << 16 | (int)cl.y << 8 | (int)cl.z);
}

int		color_angle(int angle, int sat)
{
	t_vec3	col;

	col.x = clamp(balance(0, 255, angle) - sat, 0, 255);
	col.y = clamp(balance(0, 255, angle + 127) - sat, 0, 255);
	col.z = clamp(balance(0, 255, angle + 255) - sat, 0, 255);
	return ((int)col.x << 16 | (int)col.y << 8 | (int)col.z);
}

int		color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		col_height(t_data *data, double h)
{
	int			color;
	double		n;
	int			i[2];

	n = clamp((h / 2048.0 / data->color_div) * 4.0, 0, 3);
	i[0] = (int)floor(n);
	i[1] = (int)ceil(n);
	color = col_lerp(data->colors[i[0]], data->colors[i[1]], n - i[0]);
	return (color);
}

void	col_input(t_data *data, t_input *input)
{
	static int i[4];
	static int sat;

	(void) input;
	if (get_key(input, SDL_SCANCODE_B))
		data->color_div -= 0.2;
	if (get_key(input, SDL_SCANCODE_N))
		data->color_div += 0.2;
	if (data->color_file)
		return ;
	if (get_key(input, SDL_SCANCODE_Z))
		i[0]++;
	if (get_key(input, SDL_SCANCODE_X))
		i[1]++;
	if (get_key(input, SDL_SCANCODE_C))
		i[2]++;
	if (get_key(input, SDL_SCANCODE_V))
		i[3]++;
	// if (input->key[SDLK_COMMA])
	// 	sat++;
	// if (input->key[SDLK_PERIOD])
	// 	sat--;
	data->colors[0] = color_angle(i[0], sat);
	data->colors[1] = color_angle(i[1], sat);
	data->colors[2] = color_angle(i[2], sat);
	data->colors[3] = color_angle(i[3], sat);
}
