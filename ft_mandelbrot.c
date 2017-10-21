/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_mandelbrot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:06:30 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/21 18:06:34 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mandelbrot(t_d *d)
{
	d->z = 270;
	d->i_max = 30;
	d->i = 0;
	d->m_x = -0.46;
	d->m_y = 0;
	d->move_x = WIDTH / 2;
	d->move_y = HEIGHT / 2;
	d->color = 1;
	ft_print_controls(d);
	ft_fractal_mandelbrot(d);
}

void	ft_fractal_mandelbrot(t_d *d)
{
	ft_print_controls(d);
	d->y = 0;
	while (d->y < HEIGHT)
	{
		d->x = 0;
		while (d->x < WIDTH)
		{
			ft_mandelbrot_count(d);
			d->x++;
		}
		d->y++;
	}
}

void	ft_mandelbrot_count(t_d *d)
{
	d->p_r = (d->x - d->move_x) / d->z + d->m_x;
	d->p_i = (d->y - d->move_y) / d->z + d->m_y;
	d->pn_r = 0;
	d->pn_i = 0;
	d->i = 0;
	while (d->pn_r * d->pn_r + d->pn_i <= 4 && d->i < d->i_max)
	{
		d->po_r = d->pn_r;
		d->po_i = d->pn_i;
		d->pn_r = d->po_r * d->po_r - d->po_i * d->po_i + d->p_r;
		d->pn_i = 2 * d->po_r * d->po_i + d->p_i;
		d->i++;
	}
	if (d->i == d->i_max)
		ft_put_pixel(d, 0xCC0033);
	else
		ft_put_pixel(d, 0x000000 + d->color * d->i);
}
