/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:16:30 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/29 19:16:32 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define W 1000
# define H 1000
# include <stdlib.h>
# include "pthread.h"
# include "libft/libft.h"
# include "mlx.h"
# include "math.h"


typedef struct	s_fractal
{
	double		move_mouse_x;
	double		move_mouse_y;
	double		c;
	int 		i;
	double 		temp_y;
	int 		change_x;
	int 		change_y;
	double		go_x;
	double		go_y;
	double		color;
	double		point_real;
	double		point_imagine;
	double		p_new_real;
	double		p_new_imagine;
	double		p_old_real;
	double		p_old_imagine;
	int 		max_iteration;
	double		z;
	double		x2;
	double		y2;
	double		x;
	double		y;
	int			b;
	int			s;
	int			e;
	void		*init_mlx;
	void		*window;
	void		*new_image;
	char		*image_arr;
	int 		choose_fractol;
	int         flag;
}				t_fractal;

int		main(int argc, char **argv);
void	create_window(t_fractal *f, char **argv);
void	fractol_selection(char *argv, t_fractal *f);
void	init_mandelbrot_fractal(t_fractal *f);
void	init_julya_fractal(t_fractal *f);
void	init_burningship_fractal(t_fractal *f);
void	mandelbrot(t_fractal *f);
void	julya(t_fractal *f);
void	burning_ship(t_fractal *f);
void	draw_pixels(t_fractal *f, int hex_value);
void	redraw(t_fractal *f);
int		keys(int keycode, t_fractal *f);
int		keys2(int keycode, t_fractal *f);
int		keys_for_mouse(int x, int y, t_fractal *f);
int		keys_for_mouse2(int button, int x, int y, t_fractal *f);

#endif
