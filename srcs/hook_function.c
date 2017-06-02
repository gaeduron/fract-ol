/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 13:12:59 by gduron            #+#    #+#             */
/*   Updated: 2017/06/02 19:03:03 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_hook(int keycode, t_env *env)
{
	void	(*f_ptr)(t_env *env);

	f_ptr = env->fract_list[env->fractal];
	if (keycode == 53)
		exit(0);
	if (keycode != 124 && keycode != 123 && keycode != 51)
		put_help(env);
	keycode == 51 ? env->roulette_on++ : 0;
	keycode == 123 ? env->palette.i-- : 0;
	keycode == 124 ? env->palette.i++ : 0;
	env->palette.i > 2 ? env->palette.i = 0 : 0;
	env->palette.i < 0 ? env->palette.i = 2 : 0;
	if (keycode == 123 || keycode == 124)
	{
		ft_bzero(env->mlx.img_data, (WIN_SIZE * WIN_SIZE) * 4);
		f_ptr(env);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	}
	return (0);
}

static void		zoom_in(int x, int y, t_env *env)
{
	void	(*f_ptr)(t_env *env);

	f_ptr = env->fract_list[env->fractal];
	env->zoom = env->zoom * 0.5;
	env->i_zoom += 5;
	env->x_padding = ((((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)x))
			+ env->x_padding - 2 * env->zoom
			+ ((((2.0 + 2) * env->zoom) / WIN_SIZE)
				* ((double)x - WIN_SIZE * 0.5)));
	env->y_padding = (((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)y))
		+ env->y_padding - 2 * env->zoom
		+ ((((2.0 + 2) * env->zoom) / WIN_SIZE)
				* ((double)y - WIN_SIZE * 0.5));
	ft_bzero(env->mlx.img_data, (WIN_SIZE * WIN_SIZE) * 4);
	f_ptr(env);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
}

static void		zoom_out(int x, int y, t_env *env)
{
	void	(*f_ptr)(t_env *env);

	f_ptr = env->fract_list[env->fractal];
	env->zoom = env->zoom * 1.5;
	env->i_zoom < 0 ? 0 : (env->i_zoom -= 5);
	env->x_padding = ((((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)x))
			+ env->x_padding - 2 * env->zoom
			+ ((((2.0 + 2) * env->zoom) / WIN_SIZE)
				* ((double)x - WIN_SIZE * 0.5)));
	env->y_padding = (((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)y))
		+ env->y_padding - 2 * env->zoom
		+ ((((2.0 + 2) * env->zoom) / WIN_SIZE)
				* ((double)y - WIN_SIZE * 0.5));
	ft_bzero(env->mlx.img_data, (WIN_SIZE * WIN_SIZE) * 4);
	f_ptr(env);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
}

int				mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 5 || button == 1)
		zoom_in(x, y, env);
	if (button == 6 || button == 2)
		zoom_out(x, y, env);
	env->ju_x_padding = ((WIN_SIZE) / 2 - x);
	env->ju_y_padding = ((WIN_SIZE) / 2 - y);
	mouse_motion_hook(x, y, env);
	return (0);
}

int				mouse_motion_hook(int x, int y, t_env *env)
{
	void	(*f_ptr)(t_env *env);

	env->roulette_on % 2 ? env->roulette++ : 0;
	(unsigned int)env->roulette > 0xffffff ? env->roulette = 1 : 0;
	f_ptr = env->fract_list[env->fractal];
	x = x + env->ju_x_padding;
	y = y + env->ju_y_padding;
	env->ju_x = (((((2.0 + 2) * env->zoom) / (WIN_SIZE))
				* (double)(x - (WIN_SIZE / 2)))) + env->x_padding;
	env->ju_y = (((((2.0 + 2) * env->zoom) / (WIN_SIZE))
				* (double)(y - (WIN_SIZE / 2)))) + env->y_padding;
	ft_bzero(env->mlx.img_data, (WIN_SIZE * WIN_SIZE) * 4);
	f_ptr(env);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	return (0);
}
