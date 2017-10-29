/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:15:29 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/29 19:15:31 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw(t_fractal *f)
{
	if (f->flag == 1)
	{
		mandelbrot(f);
	}
	else if (f->flag == 2)
	{
		burning_ship(f);
	}
	else if (f->flag == 3)
	{
		julya(f);
	}
}

int		keys(int keycode, t_fractal *f)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 2)
		f->go_x -= 0.03;
	else if (keycode == 0)
		f->go_x += 0.03;
	else if (keycode == 1)
		f->go_y -= 0.03;
	else if (keycode == 13)
		f->go_y += 0.03;
	else if (keycode == 7)
		f->z -= 10;
	else
		keys2(keycode, f);
	redraw(f);
	mlx_put_image_to_window(f->init_mlx, f->window, f->new_image, 0, 0);
	return (0);
}

int		keys2(int keycode, t_fractal *f)
{
	if (keycode == 6)
		f->z += 10;
	else if (keycode == 12)
		f->max_iteration += 1;
	else if (keycode == 14)
		f->max_iteration -= 1;
	else if (keycode == 18)
		f->color -= 1000;
	else if (keycode == 19)
		f->color += 1000;
	else if (keycode == 49)
	{
		if (f->flag == 1)
			init_mandelbrot_fractal(f);
		else if (f->flag == 2)
			init_julya_fractal(f);
		else if (f->flag == 3)
			init_burningship_fractal(f);
	}
	return (0);
}
