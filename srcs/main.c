/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:51:56 by gduron            #+#    #+#             */
/*   Updated: 2017/05/29 16:28:26 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		init_env(t_env *env)
{
	if (!(env->mlx.mlx = mlx_init()))
			return (0);
	if (!(env->mlx.win = mlx_new_window(env->mlx.mlx,
					WIN_SIZE, WIN_SIZE, "fractol")))
			return (0);
	if (!(env->mlx.img = mlx_new_image(env->mlx.mlx, WIN_SIZE, WIN_SIZE)))
		return (0);
	env->mlx.img_data = mlx_get_data_addr(env->mlx.img, &env->mlx.bpp,
			&env->mlx.size_line, &env->mlx.endian);
	env->palette[0] = 0xff;
	env->palette[1] = 0xffff00;
	env->palette[2] = 0x3030ff;
	env->palette[3] = 0xffff30;
	env->palette[4] = 0x6060ff;
	env->palette[5] = 0xffff60;
	env->palette[6] = 0x9090ff;
	env->palette[7] = 0xffff90;
	env->palette[8] = 0xbbbbbb;
	env->fract_list[0] = &mandelbrot;
	env->fract_list[1] = &mandelbrot;
	env->fract_list[2] = &mandelbrot;
	return (1);
}

int				main(int ac, char **av)
{
	static	t_env	env;

	if (!(init_env(&env)))
	{
		ft_printf("error: mlx failed");
		return(0);
	}
	if (ac == 2)
	{
		if (ft_atoi(av[1]) > 0 && ft_atoi(av[1]) < 4)
		{
			env.fractal = ft_atoi(av[1]);
			do_fractol(&env);
			 return (0);
		}
	}
	ft_printf("usage: ./fractol ");
	ft_printf("1 = Mandelbrot || 2 = Julia || 3 = modulo\n");
	return (0);
}
