/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:30 by mploux            #+#    #+#             */
/*   Updated: 2017/05/03 16:54:11 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_inputs(t_data *data)
{
	t_input *input;

	if (!(input = (t_input *)ft_memalloc(sizeof(t_input))))
		error("malloc error !");
	ft_bzero(input->key, KEY_SIZE);
	ft_bzero(input->button, BUTTON_SIZE);
	input->x = 0;
	input->y = 0;
	data->input = input;
}

void		handle_events(t_data *data, SDL_Event *event)
{
	if (event->type == SDL_QUIT || (event->type == SDL_KEYDOWN &&
		event->key.keysym.sym == SDLK_ESCAPE))
		exit_fdf(data);
	if (event->type == SDL_KEYDOWN)
		update_keys_down(event->key.keysym.scancode, data);
	if (event->type == SDL_KEYUP)
		update_keys_up(event->key.keysym.scancode, data);
}

void		update_keys_down(int key, t_data *data)
{
	if (key == SDL_SCANCODE_1)
	{
		if (data->projection)
			data->projection = 0;
		else
			data->projection = 1;
	}
	if (key == SDL_SCANCODE_2)
	{
		if (data->filled_mode)
			data->filled_mode = 0;
		else
			data->filled_mode = 1;
	}
	if (key < KEY_SIZE)
		data->input->key[key] = 1;
}

void		update_keys_up(int key, t_data *data)
{
	if (key < KEY_SIZE)
		data->input->key[key] = 0;
}

int			get_key(t_input *input, int key)
{
	if (key < KEY_SIZE)
		return (input->key[key]);
	return (0);
}
