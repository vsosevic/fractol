# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/21 18:05:42 by vsosevic          #+#    #+#              #
#    Updated: 2017/10/21 18:06:02 by vsosevic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAG = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

SRC = main.c \
	  ft_fractal_mandelbrot.c \
	  ft_fractal_julya.c \
	  ft_fractal_burning_ship.c \
	  ft_fractals_key_hook.c \
	  
OBJ = main.o \
	  ft_fractal_mandelbrot.o \
	  ft_fractal_julya.o \
	  ft_fractal_burning_ship.o \
	  ft_fractals_key_hook.o \
	  
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
