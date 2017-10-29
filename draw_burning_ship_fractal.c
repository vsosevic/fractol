/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship_fractal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:14:38 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/29 19:16:12 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		help(t_fractal *f)
{
	f->point_real = (f->x - f->change_x) / f->z + f->go_x;
	f->point_imagine = (f->y - f->change_y) / f->z + f->go_y;
	f->p_new_real = 0;
	f->p_new_imagine = 0;
	f->i = 0;
	while (f->p_new_real * f->p_new_real + f->p_new_imagine *
		f->p_new_imagine <= 4 && f->i < f->max_iteration)
	{
		f->p_old_real = f->p_new_real;
		f->p_old_imagine = f->p_new_imagine;
		f->p_new_real = f->p_old_real * f->p_old_real
			- f->p_old_imagine * f->p_old_imagine + f->point_real;
		f->p_new_imagine = fabs(2 * f->p_old_real * f->p_old_imagine)
			+ f->point_imagine;
		f->i++;
	}
	if (f->i == f->max_iteration)
		draw_pixels(f, 0x000000);
	else
		draw_pixels(f, 0xcc0033 + f->color * f->i);
}

void			burning_ship(t_fractal *f)
{
	f->y = 0;
	while (f->y < H)
	{
		f->x = 0;
		while (f->x < W)
		{
			help(f);
			f->x++;
		}
		f->y++;
	}
}
