/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:58:26 by gduron            #+#    #+#             */
/*   Updated: 2017/06/02 17:36:14 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			scale_coordinates(t_env *env, double *x0, double *y0)
{
	*x0 = (((((2.0 + 2) * env->zoom) / WIN_SIZE)) * (double)env->px)
		- 2 * env->zoom + env->x_padding;
	*y0 = (((((2.0 + 2) * env->zoom) / WIN_SIZE)) * (double)env->py)
		- 2 * env->zoom + env->y_padding;
}

static void		write_mandelbrot(t_env *env, int i)
{
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	x_tmp;

	scale_coordinates(env, &x0, &y0);
	x = 0.0;
	y = 0.0;
	x_tmp = 0;
	while (x * x + y * y < 2 * 2 && i < 30 + env->i_zoom)
	{
		x_tmp = (x) * (x) - y * y + x0;
		y = 2 * (y) * (x) + y0;
		x = x_tmp;
		i++;
	}
	if ((i) < 30 + env->i_zoom)
		img_pixel_put(env, env->px, env->py, get_color(i, env));
}

void			mandelbrot(t_env *env)
{
	env->py = 0;
	while (env->py < WIN_SIZE)
	{
		env->px = 0;
		while (env->px < WIN_SIZE)
		{
			write_mandelbrot(env, 0);
			env->px++;
		}
		env->py++;
	}
}
