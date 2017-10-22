/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:06:13 by vsosevic          #+#    #+#             */
/*   Updated: 2017/10/21 18:06:18 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# define WIDTH 1000
# define HEIGHT 1000

typedef struct	s_d
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*image_info;
	int			selected_fractol;
	int			bpp;
	int			s;
	int			e;
	double		x;
	double		x1;
	double		y;
	double		y1;
	double		z;
	double		c;
	int			i;
	int			i_max;
	double		tmp_y;
	double		p_r;
	double		p_i;
	double		pn_r;
	double		pn_i;
	double		po_r;
	double		po_i;
	int			move_x;
	int			move_y;
	double		m_x;
	double		m_y;
	double		x_mouse;
	double		y_mouse;
	double		color;

}				t_d;

int				mouse_hook(int x, int y, t_d *d);
void			ft_selected_fractol(t_d *d, char *argv);
void			ft_mandelbrot_init(t_d *d);
void			ft_burning_ship_init(t_d *d);
void			ft_julya_init(t_d *d);
int				ft_key_hook_m(int keycode, t_d *d);
int				ft_key_hook_f(int keycode, t_d *d);
int				ft_mouse_hook_m(int mousecode, int x, int y, t_d *d);
int				ft_print_controls(t_d *d);
int				ft_write_burning_ship(t_d *d);
void			ft_put_pixel(t_d *d, int hex_value);
void			ft_action(t_d *d);

#endif
