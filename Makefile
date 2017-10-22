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
	  ft_mandelbrot.c \
	  ft_julya.c \
	  ft_burning_ship.c \
	  ft_key_hook.c \
	  ft_output_functions.c \
	  
OBJ = main.o \
	  ft_mandelbrot.o \
	  ft_julya.o \
	  ft_burning_ship.o \
	  ft_key_hook.o \
	  ft_output_functions.o \
	  
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
