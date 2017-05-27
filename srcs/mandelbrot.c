/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 11:58:26 by gduron            #+#    #+#             */
/*   Updated: 2017/05/27 15:35:57 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	scale_coordinates(int *px, int *py, double *x0, double *y0)
{
	*x0 = (((1.0 + 2.5) / WIN_SIZE) * (double)*px) - 2.5;
	*y0 = (((1.0 + 1.0) / WIN_SIZE) * (double)*py) - 1.0;
	*y0 *= 1.5;
}

void 			mandelbrot(t_env *env, int px, int py, int i)
{
	double	x0;
	double	y0;
	double	x;
	double	y;
	double 	x_tmp;

	scale_coordinates(&px, &py, &x0, &y0);
	x = 0.0;
	y = 0.0;
	x_tmp = 0;
	while (x*x + y*y < 2*2 && i < 30)
	{
		x_tmp = x*x - y*y + x0;
		y = 2*y*x + y0;
		x = x_tmp;
		i++;
	}
	if (i < 30)
		mlx_pixel_put(env->mlx, env->win, px, py, env->palette[(i - 1) % 8]);
}
