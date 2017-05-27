/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 12:51:56 by gduron            #+#    #+#             */
/*   Updated: 2017/05/27 15:43:51 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static	void	get_flag(int ac, char **av, t_env *env)
{
	env->padding_x = ac > 2 ? ft_atoi(av[2]) : 10;
	if (ac > 2)
		env->padding_x = av[2][0] == 'x' ? 1 : env->padding_x;
	env->padding_y = ac > 3 ? ft_atoi(av[3]) : 1;
	if (ac > 3)
		env->padding_y = av[3][0] == 'x' ? 1 : env->padding_y;
	env->scale = ac > 4 ? ft_atoi(av[4]) : 1;
	if (ac > 4)
		env->scale = av[4][0] == 'x' || env->scale == 0 ? 1 : env->scale;
	env->perspective = ac > 5 ? ft_atoi(av[5]) : 0;
	if (ac > 5)
		env->perspective = av[5][0] == 'x' ? 0 : env->perspective;
	env->size = ac > 6 ? ft_atoi(av[6]) : 1;
	if (ac > 6)
		env->size = av[6][0] == 'x' ? 1 : env->size;
	env->zoom = ac > 7 ? ft_atoi(av[7]) : 0;
	if (ac > 7)
		env->zoom = av[7][0] == 'x' ? 0 : env->zoom;
}*/

static	int		init_env(t_env *env)
{
	if (!(env->mlx = mlx_init()))
			return (0);
	if (!(env->win = mlx_new_window(env->mlx,
					WIN_SIZE, WIN_SIZE, "fractol")))
			return (0);
	env->palette[0] = 0x6000ff;
	env->palette[1] = 0xc011ee;
	env->palette[2] = 0x022dd;
	env->palette[3] = 0x6033cc;
	env->palette[4] = 0xc044bb;
	env->palette[5] = 0x0055aa;
	env->palette[6] = 0x606699;
	env->palette[7] = 0xc07788;
	env->palette[8] = 0x06666;
	env->fract_list[0] = &mandelbrot;
	env->fract_list[1] = &mandelbrot;
	env->fract_list[2] = &mandelbrot;
	return (1);
}

int				main(int ac, char **av)
{
	t_env	env;

	if (!(init_env(&env)))
	{
		ft_printf("error: mlx failed");
		return(0);
	}
	if (ac == 2)
	{
//		get_flag(ac, av, &env);
		if (ft_atoi(av[1]) > 0 && ft_atoi(av[1]) < 4)
		{
			do_fractol(ft_atoi(av[1]), &env);
			 return (0);
		}
	}
	ft_printf("usage: ./fractol ");
	ft_printf("1 = Mandelbrot || 2 = Julia || 3 = modulo\n");
	return (0);
}
