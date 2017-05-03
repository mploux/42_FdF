/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:10:33 by mploux            #+#    #+#             */
/*   Updated: 2017/05/03 16:50:12 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <SDL.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "maths.h"
# include "graphics.h"

# define KEY_SIZE 284
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
	SDL_Window	*sdl_win;
	SDL_Surface	*sdl_surface;
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
void			new_sdl_display(t_data *data, const char *title, int width, int height);
int				create_fdf(t_data *data, const char *name, int width, int height);
void			sdl_loop(t_data *data, int (*loop)(t_data *));
void			loop_fdf(t_data *data, t_mesh *mesh);
void			exit_fdf(t_data *data);
t_mesh			*load_mesh(t_data *data, char *file);
void			load_colors(t_data *data, char *file);
void			col_input(t_data *data, t_input *input);
void			init_inputs(t_data *data);
void			handle_events(t_data *data, SDL_Event *event);
void			update_keys_down(int key, t_data *data);
void			update_keys_up(int key, t_data *data);
int				get_key(t_input *input, int key);

#endif
