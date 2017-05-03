/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 05:39:03 by mploux            #+#    #+#             */
/*   Updated: 2017/05/03 15:15:56 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_bitmap		*new_bitmap(t_data *data, int width, int height)
{
	t_bitmap *b;

	if (!(b = (t_bitmap *)ft_memalloc(sizeof(t_bitmap))))
		error("malloc error !");
	b->sdl_renderer = SDL_CreateRenderer(data->sdl_win, -1, 0);
	b->sdl_texture = SDL_CreateTexture(b->sdl_renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);
	b->pixels = ft_memalloc(sizeof(int) * width * height);
	b->width = width;
	b->height = height;
	return (b);
}

void			bitmap_draw_pix(t_bitmap *b, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= b->width || y >= b->height)
		return ;
	b->pixels[x + y * b->width] = color;
}

void			bitmap_update(t_bitmap *b)
{
	SDL_UpdateTexture(b->sdl_texture, NULL, b->pixels, b->width * sizeof(int));
	SDL_RenderCopy(b->sdl_renderer, b->sdl_texture, NULL, NULL);
	SDL_RenderPresent(b->sdl_renderer);
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
			bitmap_draw_pix(b, x, y, 0);
	}
}
