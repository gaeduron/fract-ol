/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:12:40 by gduron            #+#    #+#             */
/*   Updated: 2017/05/27 15:12:34 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# define WIN_SIZE 1000

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			palette[9];
	void		*fract_list[3];
	int			zoom;
	t_point		a;
}				t_env;

void			do_fractol(int fractal, t_env *env);
int				main(int ac, char **av);
int				close_tab(int keycode);
void			mandelbrot(t_env *env, int px, int py, int i);
#endif
