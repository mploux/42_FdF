/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:10:33 by mploux            #+#    #+#             */
/*   Updated: 2016/12/14 21:32:13 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <string.h>
# include "input.h"
# include "mlx.h"
# include "libft.h"
# include "maths.h"
# include "graphics.h"

# define KEY_SIZE 1024
# define BUTTON_SIZE 6

typedef struct s_mesh		t_mesh;
typedef struct s_bitmap		t_bitmap;

typedef struct	s_scanline
{
	int			value[2];
	int			color[2];
	double		depth[2];
}				t_scanline;

typedef struct	s_win
{
	void		*ctx;
	int			w;
	int			h;
	char		*name;
}				t_win;

typedef struct	s_input
{
	int			key[KEY_SIZE];
	int			button[BUTTON_SIZE];
	int			x;
	int			y;
}				t_input;

typedef struct	s_camera
{
	t_mat4		proj;
	double		aspect;
	double		z_near;
	double		z_far;
	t_vec2		pos;
	t_vec2		rot;
	t_vec3		scale;
	double		zoom;
	t_mat4		trs;
	t_vec2		apos;
	t_vec2		arot;
	t_vec2		ascale;
	int			azoom;
}				t_camera;

typedef struct	s_data
{
	void		*mlx;
	t_win		*win;
	t_input		*input;
	t_camera	*camera;
	int			colors[4];
	t_vec3		acolors[4];
	double		color_div;
	int			color_file;
	double		aspect;
	t_bitmap	*framebuffer;
	t_mat4		screen_space;
	t_mesh		*mesh;
	t_scanline	*scan_line;
	double		*zbuffer;
	int			filled_mode;
	int			projection;
}				t_data;

int				error(char *error);
int				create_fdf(t_data *data, const char *name, int width,
																	int height);
void			loop_fdf(t_data *data, t_mesh *mesh);
void			exit_fdf(t_data *data);
t_mesh			*load_mesh(t_data *data, char *file);
void			load_colors(t_data *data, char *file);
void			col_input(t_data *data, t_input *input);
void			mlx_input_hook(t_data *data);
t_input			*new_input();
int				key_hook(int key, t_data *input);
int				key_up_hook(int key, t_data *input);

#endif
