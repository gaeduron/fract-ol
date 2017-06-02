/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:13:48 by gduron            #+#    #+#             */
/*   Updated: 2017/06/02 17:29:46 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_help(t_env *env)
{
	mlx_string_put(env->mlx.mlx, env->mlx.win,
			20, 10, 0xff00, "Use [<-][->] arrow to change color");
	mlx_string_put(env->mlx.mlx, env->mlx.win,
			20, 30, 0xff00, "[DEL] and mouse motion for psychedelic mode");
	mlx_string_put(env->mlx.mlx, env->mlx.win, 20, 470, 0xFF6600,
			"NEVER USE [DEL] IF YOU SUFFER FROM EPILEPSY");
}

void	img_pixel_put(t_env *env, int x, int y, int color)
{
	env->mlx.img_data[(x * 4 + 3) + (y * env->mlx.size_line)] = color >> 24;
	env->mlx.img_data[(x * 4 + 2) + (y * env->mlx.size_line)] = color >> 16;
	env->mlx.img_data[(x * 4 + 1) + (y * env->mlx.size_line)] = color >> 8;
	env->mlx.img_data[(x * 4 + 0) + (y * env->mlx.size_line)] = color;
}
