# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 21:06:00 by vsosevic          #+#    #+#              #
#    Updated: 2017/11/14 21:06:12 by vsosevic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAG = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

SRC = main.c \
	  fractol_selection_draw.c \
	  draw_julya_fractal.c \
	  draw_burning_ship_fractal.c \
	  actions_keys.c \
	  actions_mouse.c \
	  init_fractals.c
	  
OBJ = main.o \
	  fractol_selection_draw.o \
	  draw_mandelbrot_fractal.o \
	  draw_julya_fractal.o \
	  draw_burning_ship_fractal.o \
	  actions_keys.o \
	  actions_mouse.o \
	  init_fractals.o
	  
	  
HEADER = fractol.h

LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	gcc  $(OBJ) $(FLAG) $(LIB) -o $(NAME)

%.o: %.c
	gcc -c -o $@ $< -Wall -Werror -Wextra 

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft
