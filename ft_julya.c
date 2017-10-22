/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julya_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:12:17 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/21 18:12:21 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julya_count(t_d *d)
{
	d->pn_r = (d->x - d->move_x) / d->z + d->m_x;
	d->pn_i = (d->y - d->move_y) / d->z + d->m_y;
	d->i = 0;
	while (d->pn_r * d->pn_r + d->pn_i * d->pn_i <= 4 && d->i < d->i_max)
	{
		d->po_r = d->pn_r;
		d->po_i = d->pn_i;
		d->pn_r = d->po_r * d->po_r - d->po_i * d->po_i + d->p_r;
		d->pn_i = 2 * d->po_r * d->po_i + d->p_i;
		if ((d->pn_r * d->pn_r + d->pn_i * d->pn_i) > 6)
			break ;
		d->i++;
	}
	if (d->i == d->i_max)
		ft_put_pixel(d, 0xCC0033);
	else
		ft_put_pixel(d, 0x000000 + d->color * d->i);
}

void	ft_julya_fractal(t_d *d)
{
	d->p_r = d->x_mouse;
	d->p_i = d->y_mouse;
	ft_print_controls(d);
	d->y = 0;
	while (d->y < HEIGHT)
	{
		d->x = 0;
		while (d->x < WIDTH)
		{
			ft_julya_count(d);
			d->x++;
		}
		d->y++;
	}
}

void	ft_julya_init(t_d *d)
{
	d->z = 270;
	d->i_max = 50;
	d->m_x = -0.46;
	d->m_y = 0;
	d->move_x = 400;
	d->move_y = 500;
	d->p_r = -0.285;
	d->p_i = -0.01;
	ft_print_controls(d);
	ft_julya_fractal(d);
}
