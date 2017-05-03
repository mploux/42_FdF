/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:44:10 by mploux            #+#    #+#             */
/*   Updated: 2016/12/12 22:40:22 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_line_x(t_data *data, t_vec4 a, t_vec4 b, t_vec2 colors)
{
	t_vec2	pos;
	int		col;
	double	depth;
	double	n;
	double	nx;

	pos.x = -1;
	pos.y = a.y;
	while (++pos.x < ABS(b.x - a.x))
	{
		n = pos.x / ABS(b.x - a.x);
		pos.y = LERP(a.y, b.y, n);
		nx = a.x + pos.x * (b.x - a.x < 0 ? -1 : 1);
		depth = LERP(a.w, b.w, n);
		if (depth < 5 * data->projection || depth < 1)
			continue;
		if (get_depth(data, (int)nx, (int)pos.y) < depth)
			continue;
		draw_depth(data, (int)nx, (int)pos.y, depth);
		col = col_height(data, col_lerp(colors.x, colors.y, n));
		draw_pix(data, (int)(nx), (int)pos.y, col);
	}
}

void	draw_line_y(t_data *data, t_vec4 a, t_vec4 b, t_vec2 colors)
{
	t_vec2	pos;
	int		col;
	double	n;
	double	depth;
	double	ny;

	pos.x = a.x;
	pos.y = -1;
	while (++pos.y < ABS(b.y - a.y))
	{
		n = pos.y / ABS(b.y - a.y);
		pos.x = LERP(a.x, b.x, n);
		ny = a.y + pos.y * (b.y - a.y < 0 ? -1 : 1);
		depth = LERP(a.w, b.w, n);
		if (depth < 5 * data->projection || depth < 1)
			continue;
		if (get_depth(data, (int)pos.x, (int)ny) < depth)
			continue;
		draw_depth(data, (int)pos.x, (int)ny, depth);
		col = col_height(data, col_lerp(colors.x, colors.y, n));
		draw_pix(data, (int)pos.x, (int)(ny), col);
	}
}
