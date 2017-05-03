/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 00:59:27 by mploux            #+#    #+#             */
/*   Updated: 2016/12/13 13:00:32 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_triangle		triangle(t_vertex a, t_vertex b, t_vertex c)
{
	t_triangle tri;

	tri.top = a;
	tri.mid = b;
	tri.bot = c;
	return (tri);
}

static void		scan_fill_line(t_data *data, double y, int scan[2], double d[2])
{
	double	color[3];
	double	depth;
	double	x;
	double	n;
	double	v_color;

	x = scan[0] - 1;
	while (++x <= scan[1])
	{
		n = (double)(x - scan[0]) / (scan[1] - scan[0] + 1);
		depth = LERP(d[0], d[1], n);
		if (depth < 5 * data->projection || depth < 5)
			continue;
		if (depth >= get_depth(data, (int)x, (int)y))
			continue;
		draw_depth(data, (int)x, (int)y, depth);
		color[0] = data->scan_line[(int)y].color[0];
		color[1] = data->scan_line[(int)y].color[1];
		v_color = col_height(data, col_lerp(color[0], color[1], n));
		draw_pix(data, x, y, v_color);
	}
}

static void		fill_scan(t_data *data, double min, double max)
{
	double	y;
	double	depth[2];
	int		scan[2];

	y = (int)ceil(min) - 1;
	if (y < 0)
		y = -1;
	while (++y <= max)
	{
		if (y >= data->win->h - 1)
			break ;
		scan[0] = data->scan_line[(int)y].value[0];
		scan[1] = data->scan_line[(int)y].value[1];
		depth[0] = data->scan_line[(int)y].depth[0];
		depth[1] = data->scan_line[(int)y].depth[1];
		scan_fill_line(data, y, scan, depth);
	}
}

static void		scan_edge(t_data *data, t_vertex top, t_vertex bot, int side)
{
	t_vec2	pos;
	double	y_diff;
	double	step;
	int		color;
	double	depth;

	y_diff = bot.s_pos.y - top.s_pos.y;
	if (y_diff <= 0)
		return ;
	step = (bot.s_pos.x - top.s_pos.x) / y_diff;
	pos.x = top.s_pos.x + (((int)ceil(top.s_pos.y)) - top.s_pos.y) * step;
	pos.y = (int)ceil(top.s_pos.y) - 1;
	clamp(pos.y, 0, data->win->h - 1);
	while (++pos.y < bot.s_pos.y)
	{
		if (pos.y >= data->win->h - 1)
			break ;
		color = col_lerp(top.col, bot.col, (pos.y - top.s_pos.y) / y_diff);
		depth = LERP(top.s_pos.w, bot.s_pos.w, (pos.y - top.s_pos.y) / y_diff);
		data->scan_line[(int)pos.y].value[side] = (int)ceil(pos.x);
		data->scan_line[(int)pos.y].color[side] = color;
		data->scan_line[(int)pos.y].depth[side] = depth;
		pos.x += step;
	}
}

void			scan_triangle(t_data *data, t_triangle tri)
{
	int tri_area;
	int side;

	tri_area = (tri.top.s_pos.x - tri.bot.s_pos.x) *
				(tri.mid.s_pos.y - tri.top.s_pos.y) -
				(tri.top.s_pos.x - tri.mid.s_pos.x) *
				(tri.bot.s_pos.y - tri.top.s_pos.y);
	side = tri_area >= 0 ? 1 : 0;
	scan_edge(data, tri.top, tri.mid, 0 + side);
	scan_edge(data, tri.mid, tri.bot, 0 + side);
	scan_edge(data, tri.top, tri.bot, 1 - side);
	fill_scan(data, tri.top.s_pos.y, tri.bot.s_pos.y);
}
