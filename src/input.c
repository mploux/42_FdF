/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:30 by mploux            #+#    #+#             */
/*   Updated: 2016/12/15 15:45:06 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_input		*new_input(void)
{
	t_input	*input;
	int		i;

	if (!(input = (t_input *)ft_memalloc(sizeof(t_input))))
		error("malloc error !");
	i = -1;
	while (++i < KEY_SIZE)
		input->key[i] = 0;
	return (input);
}

int			key_hook(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		exit_fdf(data);
	if (key == KEY_1)
	{
		if (data->projection)
			data->projection = 0;
		else
			data->projection = 1;
	}
	if (key == KEY_2)
	{
		if (data->filled_mode)
			data->filled_mode = 0;
		else
			data->filled_mode = 1;
	}
	data->input->key[key] = 1;
	return (1);
}

int			key_up_hook(int key, t_data *data)
{
	data->input->key[key] = 0;
	return (1);
}
