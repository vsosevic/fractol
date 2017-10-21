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

int		ft_valid(int argc, char *argv)
{
	if (argc != 2 || (argv[0] != 'F' && argv[0] != 'S' && argv[0] != 'T'))
	{
		write(1, "Put letter F for fractal Mandelbrot\n", 36);
		write(1, "Put letter S for fractal Julia\n", 31);
		write(1, "Put letter T for fractal BurningShip\n", 37);
		return (0);
	}
	return (1);
}

void	ft_which_fractol_is(t_d *d, char *argv)
{
	if (argv[0] == 'F')
	{
		d->which_fractol = 1;
		ft_standart_mandelbrot(d);
	}
	if (argv[0] == 'S')
	{
		d->which_fractol = 2;
		ft_standart_julya(d);
	}
	if (argv[0] == 'T')
	{
		d->which_fractol = 3;
		ft_standart_burning_ship(d);
	}
	ft_action(d);
}

void	ft_action(t_d *d)
{
	if (d->which_fractol == 1)
		ft_fractal_mandelbrot(d);
	if (d->which_fractol == 2)
		ft_fractal_julya(d);
	if (d->which_fractol == 3)
		ft_fractal_burning_ship(d);
}

int		main(int argc, char **argv)
{
	t_d *d;

	d = (t_d*)malloc(sizeof(t_d));
	if (ft_valid(argc, argv[1]) == 0)
		return (0);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "FRACTOL");
	d->image = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->image_info = mlx_get_data_addr(d->image, &d->bpp, &d->s, &d->e);
	ft_which_fractol_is(d, argv[1]);
	mlx_hook(d->win, 6, 0, mouse_hook, d);
	mlx_hook(d->win, 2, 0, ft_key_hook_m, d);
	mlx_mouse_hook(d->win, ft_mouse_hook_m, d);
	mlx_loop(d->mlx);
}
