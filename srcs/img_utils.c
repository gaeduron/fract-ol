/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 15:13:48 by gduron            #+#    #+#             */
/*   Updated: 2017/05/28 15:54:16 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pixel_put(t_env *env, int x, int y, int color)
{
	env->mlx.img_data[(x * 4 + 3) + (y * env->mlx.size_line)] = color >> 24;
	env->mlx.img_data[(x * 4 + 2) + (y * env->mlx.size_line)] = color >> 16;
	env->mlx.img_data[(x * 4 + 1) + (y * env->mlx.size_line)] = color >> 8;
	env->mlx.img_data[(x * 4 + 0) + (y * env->mlx.size_line)] = color;
}
