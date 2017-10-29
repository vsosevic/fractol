/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julya_fractal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:16:48 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/29 19:16:49 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		help(t_fractal *f)
{
	f->p_new_real = (f->x - f->change_x) / f->z + f->go_x;
	f->p_new_imagine = (f->y - f->change_y) / f->z + f->go_y;
	f->i = 0;
	while (f->p_new_real * f->p_new_real + f->p_new_imagine
		* f->p_new_imagine <= 4 && f->i < f->max_iteration)
	{
		f->p_old_real = f->p_new_real;
		f->p_old_imagine = f->p_new_imagine;
		f->p_new_real = f->p_old_real * f->p_old_real - f->p_old_imagine
			* f->p_old_imagine + f->point_real;
		f->p_new_imagine = 2 * f->p_old_real * f->p_old_imagine
			+ f->point_imagine;
		if ((f->p_new_real * f->p_new_real + f->p_new_imagine
			* f->p_new_imagine) > 6)
			break ;
		f->i++;
	}
	if (f->i == f->max_iteration)
		draw_pixels(f, 0xCC0033);
	else
		draw_pixels(f, 0x000000 + f->color * f->i);
}

void			julya(t_fractal *f)
{
	f->point_real = f->move_mouse_x;
	f->point_imagine = f->move_mouse_y;
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
