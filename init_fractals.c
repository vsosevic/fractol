/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:16:55 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/29 19:16:57 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_print_controls(t_fractal *f)
{
	char	**output_text;
	int		i;
	int		x;
	int		y;

	output_text = (char**)malloc(sizeof(*output_text) * 100);
	output_text[0] = "- anykey: START";
	output_text[1] = "- W and S: Vertical movement";
	output_text[2] = "- A and D: Horizontal movement";
	output_text[3] = "- Q and E: Increase or decrease precision";
	output_text[4] = "- Z and X: Zoom";
	output_text[5] = "- 1 and 2: Change COLOR";
	output_text[6] = "- Space: Return to default";
	output_text[7] = "- ESC: EXIT";
	i = 0;
	x = 300;
	y = 100;
	mlx_string_put(f->init_mlx, f->window, 350, 100, 0xcc0033, "INSTRUCTION");
	while (i <= 6)
	{
		mlx_string_put(f->init_mlx, f->window, x, y += 100, 0xffff00,
			output_text[i]);
		i++;
	}
	return (0);
}

void	init_mandelbrot_fractal(t_fractal *f)
{
	f->change_x = W / 2;
	f->change_y = H / 2;
	f->color = 1;
	f->z = 270;
	f->max_iteration = 30;
	f->i = 0;
	f->go_x = -0.46;
	f->go_y = 0;
	ft_print_controls(f);
	mandelbrot(f);
}

void	init_julya_fractal(t_fractal *f)
{
	f->change_x = 400;
	f->change_y = 500;
	f->point_real = -0.285;
	f->point_imagine = -0.01;
	f->z = 250;
	f->max_iteration = 45;
	f->go_x = -0.26;
	f->go_y = 0;
	ft_print_controls(f);
	julya(f);
}

void	init_burningship_fractal(t_fractal *f)
{
	f->change_x = W / 2;
	f->change_y = H / 2;
	f->z = 250;
	f->max_iteration = 20;
	f->go_x = 0;
	f->go_y = 0;
	ft_print_controls(f);
	burning_ship(f);
}
