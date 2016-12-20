/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:00:00 by mploux            #+#    #+#             */
/*   Updated: 2016/12/14 21:33:52 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "maths.h"

void	draw_text(t_data *data, t_vec2 pos, int color, char *string)
{
	mlx_string_put(data->mlx, data->win->ctx, pos.x, pos.y, color, string);
}

void	draw_pix(t_data *data, double x, double y, int color)
{
	bitmap_draw_pix(data->framebuffer, (int)x, (int)y, color);
}

void	draw_line(t_data *data, t_vertex a, t_vertex b, t_vec2 colors)
{
	if (!in_view_frustum(&a) && !in_view_frustum(&b))
		return ;
	if (ABS(b.s_pos.x - a.s_pos.x) > ABS(b.s_pos.y - a.s_pos.y))
		draw_line_x(data, a.s_pos, b.s_pos, colors);
	else
		draw_line_y(data, a.s_pos, b.s_pos, colors);
}

void	draw_triangle(t_data *data, t_triangle tri, t_mat4 trs)
{
	double tri_area;

	if (!in_view_frustum(&tri.top) && !in_view_frustum(&tri.mid) &&
		!in_view_frustum(&tri.bot))
		return ;
	vertex_transform(data, &tri.top, trs);
	vertex_transform(data, &tri.mid, trs);
	vertex_transform(data, &tri.bot, trs);
	tri_area = (tri.top.s_pos.x - tri.bot.s_pos.x) *
				(tri.mid.s_pos.y - tri.top.s_pos.y) -
				(tri.top.s_pos.x - tri.mid.s_pos.x) *
				(tri.bot.s_pos.y - tri.top.s_pos.y);
	if (tri_area <= 0)
		return ;
	if (tri.top.s_pos.y > tri.mid.s_pos.y)
		ft_swap(&tri.top, &tri.mid, sizeof(t_vertex));
	if (tri.mid.s_pos.y > tri.bot.s_pos.y)
		ft_swap(&tri.mid, &tri.bot, sizeof(t_vertex));
	if (tri.top.s_pos.y > tri.mid.s_pos.y)
		ft_swap(&tri.top, &tri.mid, sizeof(t_vertex));
	scan_triangle(data, tri);
}
