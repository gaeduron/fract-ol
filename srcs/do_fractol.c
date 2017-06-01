/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:54:39 by gduron            #+#    #+#             */
/*   Updated: 2017/05/30 15:43:12 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				close_tab(int keycode, t_env *env)
{
	int i;

	i = 0;
	ft_printf("key = %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 51)
	{
		while (i < (WIN_SIZE * WIN_SIZE) * 4)
		{
			env->mlx.img_data[i++] = 0;
		}
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win,
				env->mlx.img, 0, 0);
	}
	return (0);
}

int				mouse_hook(int button, int x, int y, t_env *env)
{
	void    (*f_ptr)(t_env *env);

	f_ptr = env->fract_list[env->fractal];
	if (button == 1)
	{
		env->zoom = env->zoom * 0.5;
		env->i_zoom += 5;
		env->x_padding = ((((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)x))
				+ env->x_padding - 2 * env->zoom
				+ ((((2.0 + 2) * env->zoom) / WIN_SIZE)
					* ((double)x - WIN_SIZE*0.5)));
		env->y_padding = (((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)y))
			+ env->y_padding - 2 * env->zoom
			+ ((((2.0 + 2) * env->zoom) / WIN_SIZE)
					* ((double)y - WIN_SIZE*0.5));
		ft_bzero(env->mlx.img_data, (WIN_SIZE * WIN_SIZE) * 4);
		f_ptr(env);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	}
	if (button == 2)
	{
		env->zoom = env->zoom * 1.5;
		env->i_zoom < 0 ? 0 : (env->i_zoom -= 5);
		env->x_padding = ((((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)x))
				+ env->x_padding - 2 * env->zoom
				+ ((((2.0 + 2) * env->zoom) / WIN_SIZE)
					* ((double)x - WIN_SIZE*0.5)));
		env->y_padding = (((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)y))
			+ env->y_padding - 2 * env->zoom
			+ ((((2.0 + 2) * env->zoom) / WIN_SIZE)
					* ((double)y - WIN_SIZE*0.5));
		ft_bzero(env->mlx.img_data, (WIN_SIZE * WIN_SIZE) * 4);
		f_ptr(env);
		mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	}
	return (0);
}

int				mouse_motion_hook(int x, int y, t_env *env)
{
	void    (*f_ptr)(t_env *env);

	ft_printf("x = %d || y = %d\n", x, y);
	f_ptr = env->fract_list[env->fractal];
	env->ju_x = (((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)x));
	env->ju_y = (((((2.0 + 2) * env->zoom) / WIN_SIZE) * (double)y));
	ft_bzero(env->mlx.img_data, (WIN_SIZE * WIN_SIZE) * 4);
	f_ptr(env);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	return (0);
}

/*static	void	free_all(t_env *env)
  {
  return ;
  }*/

void			do_fractol(t_env *env)
{
	void	(*f_ptr)(t_env *env);

	env->zoom = 1;
	env->i_zoom = 0;
	f_ptr = env->fract_list[env->fractal];
	f_ptr(env);
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img, 0, 0);
	mlx_key_hook(env->mlx.win, close_tab, env);
	mlx_mouse_hook(env->mlx.win, mouse_hook, env);
	mlx_hook(env->mlx.win, 6, (1L<<6), mouse_motion_hook, env);
	mlx_loop(env->mlx.mlx);
	//	free_all(env);
	return ;
}
