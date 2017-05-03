/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:07:59 by mploux            #+#    #+#             */
/*   Updated: 2016/12/15 15:55:16 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "graphics.h"
#include <stdlib.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	t_data	*data;
	t_mesh	*mesh;

	if (ac < 2 || ac > 3)
		error("usage: fdf source_file [color_file]");
	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		error("malloc error !");
	create_fdf(data, "FdF", 720, 480);
	if (ac == 3)
		load_colors(data, av[2]);
	else
	{
		data->color_div = 20.0;
		data->color_file = 0;
	}
	mesh = load_mesh(data, av[1]);
	if (mesh->w <= 1 || mesh->h <= 1)
		error("map error: map to small !");
	loop_fdf(data, mesh);
	return (0);
}
