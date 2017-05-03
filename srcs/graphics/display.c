/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 17:50:10 by mploux            #+#    #+#             */
/*   Updated: 2017/05/03 16:13:54 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_sdl_display(t_data *data, const char *title, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error("sdl error: unable to initialize sdl !");
	data->sdl_win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											width,
											height,
											0);
	if (!data->sdl_win)
		error("sdl error: unable to create window !");
	data->win->w = width;
	data->win->h = height;
	data->win->name = (char *)title;
}

void	sdl_loop(t_data *data, int (*loop)(t_data *))
{
	SDL_Event event;

	SDL_SetRenderDrawColor(data->framebuffer->sdl_renderer, 255, 0, 255, 255);
	SDL_RenderPresent(data->framebuffer->sdl_renderer);
	SDL_RenderClear(data->framebuffer->sdl_renderer);
	while (1)
	{
		while (SDL_PollEvent(&event) != 0)
			handle_events(data, &event);
		loop(data);
	}
}
