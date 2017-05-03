/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:57:52 by mploux            #+#    #+#             */
/*   Updated: 2017/05/03 15:20:56 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "fdf.h"
# include "maths.h"

typedef struct s_data		t_data;
typedef struct s_scanline	t_scanline;
typedef struct s_camera		t_camera;
typedef struct s_input		t_input;

typedef struct	s_bitmap
{
	t_data			*data;
	SDL_Renderer	*sdl_renderer;
	SDL_Texture		*sdl_texture;
	int				width;
	int				height;
	int				*pixels;
}				t_bitmap;

typedef struct	s_vertex
{
	t_data		*data;
	t_vec4		pos;
	t_vec4		s_pos;
	t_vec2		sc;
	int			w;
	int			h;
	int			col;
}				t_vertex;

typedef struct	s_mesh
{
	t_data		*data;
	t_vertex	*vertices;
	int			*indices;
	t_list		*v_list;
	int			w;
	int			h;
	int			max_y;
}				t_mesh;

typedef struct	s_triangle
{
	t_vertex	top;
	t_vertex	mid;
	t_vertex	bot;
}				t_triangle;

void			draw_text(t_data *data, t_vec2 pos, int color, char *string);
void			draw_pix(t_data *data, double x, double y, int color);
void			draw_line(t_data *data, t_vertex a, t_vertex b, t_vec2 colors);
void			draw_triangle(t_data *data, t_triangle tri, t_mat4 trs);
t_scanline		*new_scanline(int height);
t_scanline		scanline(int value0, int value1, int color0, int color1);
void			clear_scanline(t_data *data, t_scanline **scan);
t_bitmap		*new_bitmap(t_data *data, int width, int height);
void			bitmap_draw_pix(t_bitmap *b, int x, int y, int color);
void			clear_bitmap(t_bitmap *b);
void			bitmap_update(t_bitmap *b);
t_vertex		vertex(t_data *data, t_vec3 pos, int color);
int				vertex_transform(t_data *data, t_vertex *vert, t_mat4 trs);
int				in_view_frustum(t_vertex *v);
t_mesh			*new_mesh(t_data *data);
void			mesh_create_indices(t_mesh *m);
void			mesh_add(t_mesh *mesh, t_vertex vertex);
void			mesh_draw_filled(t_mesh *m, t_mat4 trs);
void			mesh_draw_wireframe(t_mesh *m, t_mat4 trs);
t_triangle		triangle(t_vertex a, t_vertex b, t_vertex c);
void			scan_triangle(t_data *data, t_triangle tri);
void			draw_line_x(t_data *data, t_vec4 a, t_vec4 b, t_vec2 colors);
void			draw_line_y(t_data *data, t_vec4 a, t_vec4 b, t_vec2 colors);
int				col_lerp(int a, int b, double n);
int				color(int r, int g, int b);
int				col_height(t_data *data, double h);
t_camera		*new_camera(t_data *data, t_vec2 rot, double zoom);
void			cam_input(t_input *input, t_camera *cam);
void			cam_update(t_camera *cam);
t_mat4			cam_transform(t_camera *cam, t_mesh *mesh);
t_mat4			cam_projection(t_data *data, t_camera *cam);
double			*new_zbuffer(int width, int height);
void			clear_zbuffer(t_data *data, double z_far);
void			draw_depth(t_data *data, int x, int y, double depth);
double			get_depth(t_data *data, int x, int y);

#endif
