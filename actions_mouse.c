/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:16:39 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/29 19:16:41 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keys_for_mouse(int x, int y, t_fractal *f)
{
	if (f)
	{
		f->move_mouse_x = ((float)x - (W / 2)) / (W / 2);
		f->move_mouse_y = ((float)y - (H / 2)) / (H / 2);
	}
	redraw(f);
	mlx_put_image_to_window(f->init_mlx, f->window, f->new_image, 0, 0);
	return (0);
}

int		keys_for_mouse2(int button, int x, int y, t_fractal *f)
{
	if (button == 4)
	{
		f->z *= 1.1;
		f->change_x = f->change_x - (x - f->change_x) * 0.1;
		f->change_y = f->change_y - (y - f->change_y) * 0.1;
	}
	else if (button == 5)
	{
		f->z *= 0.9;
		f->change_x = f->change_x + (x - f->change_x) * 0.1;
		f->change_y = f->change_y + (y - f->change_y) * 0.1;
	}
	redraw(f);
	mlx_put_image_to_window(f->init_mlx, f->window, f->new_image, 0, 0);
	return (0);
}
