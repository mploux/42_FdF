/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 05:39:03 by mploux            #+#    #+#             */
/*   Updated: 2016/12/15 14:26:10 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_bitmap		*new_bitmap(t_data *data, int width, int height)
{
	t_bitmap *b;

	if (!(b = (t_bitmap *)ft_memalloc(sizeof(t_bitmap))))
		error("malloc error !");
	b->data = data;
	if (!(b->ctx = mlx_new_image(data->mlx, width, height)))
		error("mlx error: mlx image failed to create !");
	b->width = width;
	b->height = height;
	b->pixels = mlx_get_data_addr(b->ctx, &b->bpp, &b->sl, &b->endian);
	b->bpp /= 8;
	return (b);
}

void			bitmap_draw_pix(t_bitmap *b, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= b->width || y >= b->height)
		return ;
	b->pixels[x * b->bpp + y * b->sl] = (color & 0xff);
	b->pixels[x * b->bpp + y * b->sl + 1] = (color & 0xff00) >> 8;
	b->pixels[x * b->bpp + y * b->sl + 2] = (color & 0xff0000) >> 16;
}

void			clear_bitmap(t_bitmap *b)
{
	int x;
	int y;

	y = -1;
	while (++y < b->height)
	{
		x = -1;
		while (++x < b->width)
		{
			b->pixels[x * b->bpp + y * b->sl] = 0;
			b->pixels[x * b->bpp + y * b->sl + 1] = 0;
			b->pixels[x * b->bpp + y * b->sl + 2] = 0;
		}
	}
}
