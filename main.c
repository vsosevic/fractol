/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:10:43 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/21 18:10:47 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_action(t_d *d)
{
	if (d->selected_fractol == 1)
	{
		ft_mandelbrot_fractal(d);
	}
	else if (d->selected_fractol == 2)
	{
		ft_julya_fractal(d);
	}
	else if (d->selected_fractol == 3)
	{
		ft_burning_ship_fractal(d);
	}
}

void	ft_selected_fractol(t_d *d, char *argv)
{
	if (argv[0] == 'M')
	{
		d->selected_fractol = 1;
		ft_mandelbrot_init(d);
	}
	else if (argv[0] == 'J')
	{
		d->selected_fractol = 2;
		ft_julya_init(d);
	}
	else if (argv[0] == 'B')
	{
		d->selected_fractol = 3;
		ft_burning_ship_init(d);
	}
	ft_action(d);
}

int		main(int argc, char **argv)
{
	t_d *d;

	d = (t_d*)malloc(sizeof(t_d));
	if (argc != 2 || 
		(argv[1][0] != 'M' && argv[1][0] != 'J' && argv[1][0] != 'B'))
	{
		ft_putstr("Usage: \n'./fractol M' - Mandelbrot\n");
		ft_putstr("'./fractol J' - Julia\n'./fractol B' - BurningShip\n");
		return (0);
	}
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "FRACTOL");
	d->image = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->image_info = mlx_get_data_addr(d->image, &d->bpp, &d->s, &d->e);
	ft_selected_fractol(d, argv[1]);
	mlx_hook(d->win, 6, 0, mouse_hook, d);
	mlx_hook(d->win, 2, 0, ft_key_hook_m, d);
	mlx_mouse_hook(d->win, ft_mouse_hook_m, d);
	mlx_loop(d->mlx);
}
