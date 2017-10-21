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

void	ft_standart_mandelbrot(t_d *d)
{
	d->z = 270;
	d->i_max = 30;
	d->i = 0;
	d->m_x = -0.46;
	d->m_y = 0;
	d->move_x = WIDTH / 2;
	d->move_y = HEIGHT / 2;
	d->color = 1;
	ft_write_mandelbrot(d);
	ft_fractal_mandelbrot(d);
}

int		ft_write_mandelbrot(t_d *d)
{
	char	**text;
	int		i;
	int		x;
	int		y;

	text = (char**)malloc(sizeof(*text) * 100);
	text[0] = "- press any BUTTON: [[ START ]]";
	text[1] = "- press W and S: << Movement along the axis X >>";
	text[2] = "- press A and D: << Movement along the axis Y >>";
	text[3] = "- press Q and E: << Increase or Decrease Iteration >>";
	text[4] = "- press Z and C: << ZOOM >>";
	text[5] = "- press 1 and 2: << Change COLOR >>";
	text[6] = "- press TAB: << Return to Initial Settings >>";
	text[7] = "- press ESC: [[ EXIT ]]";
	i = 0;
	x = 300;
	y = 100;
	mlx_string_put(d->mlx, d->win, 350, 100, 0xcc0033, "INSTRUCTION");
	while (i <= 6)
	{
		mlx_string_put(d->mlx, d->win, x, y += 100, 0xffff00, text[i]);
		i++;
	}
	return (0);
}

void	ft_put_pixel(t_d *d, int hex_value)
{
	int i;

	i = (d->x * 4) + (d->y * d->s);
	d->image_info[i + 2] = ((hex_value >> 16) & 0xFF);
	d->image_info[i + 1] = ((hex_value >> 8) & 0xFF);
	d->image_info[i] = ((hex_value) & 0xFF);
}

void	ft_fractal_mandelbrot(t_d *d)
{
	ft_write_mandelbrot(d);
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
