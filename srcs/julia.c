/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 10:51:22 by gduron            #+#    #+#             */
/*   Updated: 2017/06/02 17:30:26 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		write_julia(t_env *env, int i)
{
	double	x0;
	double	y0;
	double	x;
	double	y;
	double	x_tmp;

	scale_coordinates(env, &x, &y);
	x0 = env->ju_x;
	y0 = env->ju_y;
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

void			julia(t_env *env)
{
	env->py = 0;
	while (env->py < WIN_SIZE)
	{
		env->px = 0;
		while (env->px < WIN_SIZE)
		{
			write_julia(env, 0);
			env->px++;
		}
		env->py++;
	}
}
