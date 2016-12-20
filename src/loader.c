/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 06:21:14 by mploux            #+#    #+#             */
/*   Updated: 2016/12/15 15:44:16 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>

static t_vertex	parse_vert(t_data *data, char *vert, t_vec2 v_pos)
{
	int			height;
	t_vec3		pos;
	int			col;

	height = ft_atoi(vert);
	pos = vec3(v_pos.x, height, v_pos.y);
	col = (double)(height * 2048);
	return (vertex(data, pos, col));
}

static int		read_line_verts(t_data *data, t_mesh *mesh, int y, char *line)
{
	int			x;
	char		**toks;
	t_vertex	vert;

	x = 0;
	toks = NULL;
	toks = ft_strsplit(line, ' ');
	if (!toks || !toks[0])
		error("loader error: invalid map !");
	while (toks[x])
	{
		vert = parse_vert(data, toks[x], vec2(x, y));
		ft_lstadd(&mesh->v_list, ft_lstnew(&vert, sizeof(t_vertex)));
		free(toks[x]);
		x++;
	}
	free(toks);
	return (x);
}

static int		load_verts(t_data *data, const int fd, t_mesh *mesh)
{
	char		*line;
	t_vec2		pos;
	int			nx;
	int			ret;

	pos.x = 0;
	pos.y = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		nx = read_line_verts(data, mesh, pos.y, line);
		if (pos.y != 0 && pos.x != nx)
			error("loader error: map vertices not aligned !");
		pos.x = nx;
		pos.y++;
		ft_strdel(&line);
	}
	if (pos.x + pos.y == 0)
		error("loader error: invalid map !");
	if (ret < 0)
		return (error("loader error: invalid file !"));
	mesh->w = pos.x;
	mesh->h = pos.y;
	return (1);
}

t_mesh			*load_mesh(t_data *data, char *file)
{
	int			fd;
	t_mesh		*m;
	int			i;
	int			index;
	int			size;

	fd = open(file, O_RDONLY);
	m = new_mesh(data);
	load_verts(data, fd, m);
	size = m->w * m->h;
	if (!(m->vertices = (t_vertex *)ft_memalloc(sizeof(t_vertex) * size)))
		error("malloc error !");
	i = -1;
	m->max_y = 0;
	while (++i < size)
	{
		index = size - i - 1;
		m->vertices[i] = *(t_vertex*)(ft_lstget(m->v_list, index)->content);
		if (m->vertices[i].pos.y > m->max_y)
			m->max_y = m->vertices[i].pos.y;
	}
	close(fd);
	mesh_create_indices(m);
	ft_lstclear(&m->v_list);
	return (m);
}

void			load_colors(t_data *data, char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**toks;
	int		col;

	i = -1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0 && ++i < 4)
	{
		toks = ft_strsplit(line, ' ');
		if (!toks[0] || !toks[1] || !toks[2] || toks[3])
			error("color error: invalid color format !");
		col = ft_atoi(toks[0]) << 16 | ft_atoi(toks[1]) << 8 | ft_atoi(toks[2]);
		data->colors[i] = col;
		free(toks[0]);
		free(toks[1]);
		free(toks[2]);
		free(toks);
		free(line);
	}
	line = NULL;
	close(fd);
	data->color_div = 20.0;
	data->color_file = 1;
}
