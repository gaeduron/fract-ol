/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 10:58:16 by gduron            #+#    #+#             */
/*   Updated: 2017/06/01 11:02:11 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		write_burning_ship(t_env *env, int i)
{
	double  x0;
	double  y0;
	double  x;
	double  y;
	double  x_tmp;

	scale_coordinates(env, &x0, &y0);
	x = 0.0;
	y = 0.0;
	x_tmp = 0;
	while (x*x + y*y < 2*2 && i < 30 + env->i_zoom)
	{
		x_tmp = (x)*(x) - y*y + x0;
		y = 2*fabs(y)*fabs(x) + y0;
		x = x_tmp;
		i++;
	}
	if ((i) < 30 + env->i_zoom)
		img_pixel_put(env, env->px, env->py, env->palette[i % 8]);
}

void			burning_ship(t_env *env)
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
