# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/19 20:14:23 by gduron            #+#    #+#              #
#    Updated: 2017/05/27 15:50:27 by gduron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = \
main.c\
do_fractol.c\
mandelbrot.c\

CC = -Wall -Werror -Wextra #-g -fsanitize=address

OBJ = $(SRC:.c=.o)

HEADER = includes

VPATH = ./srcs

all: $(NAME)

$(NAME): $(SRC)
	@echo "Compiling \033[92mLibft\033[0m..."
	@make -C Libft/
	@echo "Compiling \033[92mMinilibx\033[0m..."
	@make -C minilibx_macos/
	@gcc -o $(NAME) $^ $(CC) -I $(HEADER) Libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
	@echo "Compilation:\033[92m OK\033[0m"

clean:
	@echo "Deleting:\033[33m *.o\033[0m"
	@make -C Libft/ clean
	@make -C minilibx_macos/ clean
	@rm -f *.o

fclean: clean
	@echo "Deleting:\033[33m libft.a\033[0m"
	@rm -f Libft/libft.a
	@echo "Deleting:\033[33m libmlx.a\033[0m"
	@rm -f minilibx_macos/libmlx.a
	@echo "Deleting:\033[33m $(NAME)\033[0m"
	@rm -f $(NAME)

t: all
	@./$(NAME)
	@echo "Compilation (main):\033[92m OK\033[0m"

re: fclean all
