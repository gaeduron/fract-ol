/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:35:14 by gduron            #+#    #+#             */
/*   Updated: 2017/06/02 16:41:59 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../Libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# define WIN_SIZE 500

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

typedef	struct	s_pal
{
	int			i;
	int			p0[16];
	int			p1[16];
	int			p2[23];
}				t_pal;

typedef struct	s_env
{
	t_mlx		mlx;
	t_pal		palette;
	int			roulette_on;
	int			roulette;
	int			fractal;
	void		*fract_list[3];
	double		zoom;
	double		i_zoom;
	double		x_padding;
	double		y_padding;
	double		ju_x;
	double		ju_y;
	int			ju_x_padding;
	int			ju_y_padding;
	int			px;
	int			py;
	t_point		a;
}				t_env;

void			do_fractol(t_env *env);
int				main(int ac, char **av);
int				key_hook(int keycode, t_env *env);
void			mandelbrot(t_env *env);
void			julia(t_env *env);
void			burning_ship(t_env *env);
void			scale_coordinates(t_env *env, double *x0, double *y0);
void			img_pixel_put(t_env *env, int x, int y, int color);
int				mouse_hook(int button, int x, int y, t_env *env);
int				mouse_motion_hook(int x, int y, t_env *env);
int				get_color(int i, t_env *env);
void			init_palette(t_env *env);
void			put_help(t_env *env);
#endif
