/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:14:54 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/29 19:14:56 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_selection(char *argv, t_fractal *f)
{
	if (argv[0] == 'M')
	{
		init_mandelbrot_fractal(f);
		f->flag = 1;
	}
	else if (argv[0] == 'B')
	{
		init_burningship_fractal(f);
		f->flag = 2;
	}
	else if (argv[0] == 'J')
	{
		init_julya_fractal(f);
		f->flag = 3;
	}
}

void	draw_pixels(t_fractal *f, int hex_value)
{
	int i;

	i = (f->x * 4) + (f->y * f->s);
	f->image_arr[i + 2] = ((hex_value >> 16) & 0xFF);
	f->image_arr[i + 1] = ((hex_value >> 8) & 0xFF);
	f->image_arr[i] = ((hex_value) & 0xFF);
}
