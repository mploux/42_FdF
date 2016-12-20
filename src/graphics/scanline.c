/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:03:46 by mploux            #+#    #+#             */
/*   Updated: 2016/12/14 13:53:15 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_scanline		scanline(int value0, int value1, int color0, int color1)
{
	t_scanline scanline;

	scanline.value[0] = value0;
	scanline.value[1] = value1;
	scanline.color[0] = color0;
	scanline.color[1] = color1;
	return (scanline);
}

t_scanline		*new_scanline(int height)
{
	t_scanline	*scan_line;
	int			i;

	if (!(scan_line = (t_scanline *)ft_memalloc(sizeof(t_scanline) * height)))
		error("malloc error !");
	i = -1;
	while (++i < height)
		scan_line[i] = scanline(0, 0, 0, 0);
	return (scan_line);
}

void			clear_scanline(t_data *data, t_scanline **scan)
{
	int y;

	y = -1;
	while (++y < data->win->h)
	{
		(*scan)[y].value[0] = 0;
		(*scan)[y].value[1] = 0;
		(*scan)[y].color[0] = 0;
		(*scan)[y].color[1] = 0;
	}
}
