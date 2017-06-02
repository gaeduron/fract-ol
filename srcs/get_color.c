/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:10:14 by gduron            #+#    #+#             */
/*   Updated: 2017/06/02 17:40:19 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		pal_1(int *pal)
{
	pal[0] = 0xff;
	pal[1] = 0xffff00;
	pal[2] = 0x2222ff;
	pal[3] = 0xffff22;
	pal[4] = 0x4444ff;
	pal[5] = 0xffff444;
	pal[6] = 0x6666ff;
	pal[7] = 0xffff66;
	pal[8] = 0x8888ff;
	pal[9] = 0xffff88;
	pal[10] = 0xaaaaff;
	pal[11] = 0xffffaa;
	pal[12] = 0xccccff;
	pal[13] = 0xffffcc;
	pal[14] = 0xeeeeff;
	pal[15] = 0xffffee;
}

static void		pal_0(int *pal)
{
	pal[0] = 0xff;
	pal[1] = 0x1100ee;
	pal[2] = 0x2200dd;
	pal[3] = 0x3300cc;
	pal[4] = 0x4400bb;
	pal[5] = 0x5500aa;
	pal[6] = 0x660099;
	pal[7] = 0x770088;
	pal[8] = 0x880077;
	pal[9] = 0x990066;
	pal[10] = 0xaa0055;
	pal[11] = 0xbb0044;
	pal[12] = 0xcc0033;
	pal[13] = 0xdd0022;
	pal[14] = 0xee0011;
	pal[15] = 0xff0000;
}

static void		pal_2(int *pal)
{
	pal[0] = 0xff;
	pal[1] = 0x22dd;
	pal[2] = 0x44bb;
	pal[3] = 0x6699;
	pal[4] = 0x8877;
	pal[5] = 0xaa55;
	pal[6] = 0xcc33;
	pal[7] = 0xee11;
	pal[8] = 0x11ee00;
	pal[9] = 0x33cc00;
	pal[10] = 0x55aa00;
	pal[11] = 0x778800;
	pal[12] = 0x996600;
	pal[13] = 0xbb4400;
	pal[14] = 0xdd2200;
	pal[15] = 0xff0000;
	pal[16] = 0xdd0022;
	pal[17] = 0xbb0044;
	pal[18] = 0x990066;
	pal[19] = 0x770088;
	pal[20] = 0x5500aa;
	pal[21] = 0x3300cc;
	pal[22] = 0x1100ee;
}

void			init_palette(t_env *env)
{
	pal_0(env->palette.p0);
	pal_1(env->palette.p1);
	pal_2(env->palette.p2);
}

int				get_color(int i, t_env *env)
{
	int		color;

	color = 0;
	env->palette.i == 0 ? color = env->palette.p0[(i + env->roulette) % 16] : 0;
	env->palette.i == 1 ? color = env->palette.p1[(i + env->roulette) % 16] : 0;
	env->palette.i == 2 ?
	color = env->palette.p2[(i + env->roulette) % 23] : 0;
	return (color);
}
