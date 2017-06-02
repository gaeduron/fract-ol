/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:54:39 by gduron            #+#    #+#             */
/*   Updated: 2017/06/02 16:39:30 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			do_fractol(t_env *env)
{
	void	(*f_ptr)(t_env *env);

	env->zoom = 1;
	env->i_zoom = 0;
	f_ptr = env->fract_list[env->fractal];
	f_ptr(env);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	mlx_key_hook(env->mlx.win, key_hook, env);
	mlx_mouse_hook(env->mlx.win, mouse_hook, env);
	mlx_hook(env->mlx.win, 6, (1L << 6), mouse_motion_hook, env);
	mlx_loop(env->mlx.mlx);
	return ;
}
