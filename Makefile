# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acakste <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 16:32:24 by acakste           #+#    #+#              #
#    Updated: 2018/09/22 15:33:07 by acakste          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = printf.c\
	  get_arg.c\
	  get_arg_2.c\
	  helpers.c\
	  helpers_2.c\
	  lib_functions.c\
	  read.c\
	  cpy.c\
	  cpy_2.c\

OBJ = printf.o\
	  get_arg.o\
	  get_arg_2.o\
	  helpers.o\
	  helpers_2.o\
	  lib_functions.o\
	  read.o\
	  cpy.o\
	  cpy_2.o\

INC = includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) -I $(INC) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
