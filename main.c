/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:15:14 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/29 19:15:16 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_window(t_fractal *f, char **argv)
{
	f->init_mlx = mlx_init();
	f->window = mlx_new_window(f->init_mlx, W, H, "fractal");
	f->new_image = mlx_new_image(f->init_mlx, W, H);
	f->image_arr = mlx_get_data_addr(f->new_image, &f->b, &f->s, &f->e);
	fractol_selection(argv[1], f);
	mlx_hook(f->window, 2, 0, keys, f);
	mlx_hook(f->window, 6, 0, keys_for_mouse, f);
	mlx_mouse_hook(f->window, keys_for_mouse2, f);
	mlx_loop(f->init_mlx);
}

int		main(int argc, char **argv)
{
	t_fractal *f;

	f = (t_fractal*)malloc(sizeof(t_fractal));
	if (argc != 2 ||
		(argv[1][0] != 'M' && argv[1][0] != 'J' && argv[1][0] != 'B'))
	{
		ft_putstr("Usage: \n'./fractol M' - Mandelbrot\n");
		ft_putstr("'./fractol J' - Julia\n'./fractol B' - BurningShip\n");
		return (0);
	}
	create_window(f, argv);
	return (0);
}
