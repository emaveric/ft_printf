# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 19:37:05 by emaveric          #+#    #+#              #
#    Updated: 2020/01/18 14:33:33 by emaveric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c modifiers.c

SRC = $(addprefix src/, $(FILES))

INC = includes/ft_printf.h

OBJ = $(addprefix obj/, $(FILES:.c=.o))

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

lib:
	@make -C libft

$(NAME): $(OBJ) lib
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

obj/%.o: src/%.c | obj
	gcc -c -I./libft $< -o $@

clean:
	rm -rf $(OBJ)
	make -C libft clean

obj:
	mkdir -p obj

fclean: clean
	/bin/rm -rf $(NAME) ./obj
	make -C libft fclean

re: fclean all