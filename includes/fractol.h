/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:12:40 by gduron            #+#    #+#             */
/*   Updated: 2017/06/01 11:02:42 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

typedef struct	s_env
{
	t_mlx		mlx;
	int			fractal;
	int			palette[9];
	void		*fract_list[3];
	double		zoom;
	double		i_zoom;
	double		x_padding;
	double		y_padding;
	double		ju_x;
	double		ju_y;
	int			px;
	int			py;
	t_point		a;
}				t_env;

void			do_fractol(t_env *env);
int				main(int ac, char **av);
int				close_tab(int keycode, t_env *env);
void			mandelbrot(t_env *env);
void			scale_coordinates(t_env *env, double *x0, double *y0);
void			img_pixel_put(t_env *env, int x, int y, int color);
void			zoom_hook(t_env *env);
#endif
