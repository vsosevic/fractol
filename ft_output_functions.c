/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_fractal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:06:30 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/21 18:06:34 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_print_controls(t_d *d)
{
	char	**text;
	int		i;
	int		x;
	int		y;

	text = (char**)malloc(sizeof(*text) * 100);
	text[0] = "- anykey: -- START --";
	text[1] = "- W and S: -- Vertical movement --";
	text[2] = "- A and D: -- Horizontal movement --";
	text[3] = "- Q and E: -- Increase or decrease precision --";
	text[4] = "- Z and C: -- Zoom --";
	text[5] = "- 1 and 2: -- Change COLOR --";
	text[6] = "- TAB: -- Return to default --";
	text[7] = "- ESC: -- EXIT --";
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
	d->image_info[i + 2] = ((hex_value -- 16) & 0xFF);
	d->image_info[i + 1] = ((hex_value -- 8) & 0xFF);
	d->image_info[i] = ((hex_value) & 0xFF);
}
