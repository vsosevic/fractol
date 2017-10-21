/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractals_key_hook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:12:00 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/21 18:12:03 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_hook_m(int button, int x, int y, t_d *d)
{
	if (button == 4)
	{
		d->z *= 1.1;
		d->move_x = d->move_x - (x - d->move_x) * 0.1;
		d->move_y = d->move_y - (y - d->move_y) * 0.1;
	}
	if (button == 5)
	{
		d->z *= 0.9;
		d->move_x = d->move_x + (x - d->move_x) * 0.1;
		d->move_y = d->move_y + (y - d->move_y) * 0.1;
	}
	ft_action(d);
	mlx_put_image_to_window(d->mlx, d->win, d->image, 0, 0);
	return (0);
}

int		ft_key_hook_f(int keycode, t_d *d)
{
	if (keycode == 6)
		d->z += 2;
	if (keycode == 12)
		d->i_max += 1;
	if (keycode == 14)
		d->i_max -= 1;
	if (keycode == 18)
		d->color -= 1000;
	if (keycode == 19)
		d->color += 1000;
	if (keycode == 48)
		ft_standart_mandelbrot(d);
	return (0);
}

int		ft_key_hook_m(int keycode, t_d *d)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 2)
		d->m_x -= 0.03;
	if (keycode == 0)
		d->m_x += 0.03;
	if (keycode == 1)
		d->m_y -= 0.03;
	if (keycode == 13)
		d->m_y += 0.03;
	if (keycode == 8)
		d->z -= 2;
	ft_key_hook_f(keycode, d);
	ft_action(d);
	mlx_put_image_to_window(d->mlx, d->win, d->image, 0, 0);
	return (0);
}

int		mouse_hook(int x, int y, t_d *d)
{
	if (d)
	{
		d->x_mouse = ((float)x - (WIDTH / 2)) / (WIDTH / 2);
		d->y_mouse = ((float)y - (HEIGHT / 2)) / (HEIGHT / 2);
	}
	ft_action(d);
	mlx_put_image_to_window(d->mlx, d->win, d->image, 0, 0);
	return (0);
}
