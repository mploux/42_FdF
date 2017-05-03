/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:34:10 by mploux            #+#    #+#             */
/*   Updated: 2016/12/14 14:23:17 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

double	*new_zbuffer(int width, int height)
{
	double *buffer;

	if (!(buffer = (double *)ft_memalloc(sizeof(double) * width * height)))
		error("malloc error !");
	return (buffer);
}

void	clear_zbuffer(t_data *data, double z_far)
{
	int i;

	i = -1;
	while (++i < data->win->w * data->win->h)
		data->zbuffer[i] = z_far;
}

void	draw_depth(t_data *data, int x, int y, double depth)
{
	if (x < 0 || y < 0 || x >= data->win->w || y >= data->win->h)
		return ;
	data->zbuffer[x + y * data->win->w] = depth;
}

double	get_depth(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->win->w || y >= data->win->h)
		return (0);
	return (data->zbuffer[x + y * data->win->w]);
}
