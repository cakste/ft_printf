# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acakste <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 16:32:24 by acakste           #+#    #+#              #
#    Updated: 2018/09/20 16:30:58 by acakste          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = srcs/printf.c srcs/get_arg.c srcs/helpers.c srcs/lib_functions.c srcs/read.c
OBJ = printf.o get_arg.o helpers.o lib_functions.o read.o
INC = includes/ft_printf.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) -I $(INC) $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

run: re
	@/bin/rm -f a.out
	@gcc main/main.c libftprintf.a
