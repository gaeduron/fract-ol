/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 13:54:39 by gduron            #+#    #+#             */
/*   Updated: 2017/05/27 15:12:58 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				close_tab(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

/*static	void	free_all(t_env *env)
{
	return ;
}*/

void			do_fractol(int fractal, t_env *env)
{
	int		x;
	int		y;
	void	(*f_ptr)(t_env *env, int px, int py, int i);

//	if (!(init_t_env(env, fd)))
//	{
//		write(1, "error\n", 6);
//		return ;
//	}
	f_ptr = env->fract_list[fractal];
	y = 0;
	while (y < WIN_SIZE)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			f_ptr(env, y, x, 0);
			x++;
		}
		y++;
	}
	mlx_key_hook(env->win, close_tab, 0);
	mlx_loop(env->mlx);
//	free_all(env);
	return ;
}
