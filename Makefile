# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acakste <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 16:32:24 by acakste           #+#    #+#              #
#    Updated: 2018/09/22 15:09:19 by acakste          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftprintf.a

SRC = 	srcs/printf.c srcs/get_arg.c srcs/helpers.c srcs/lib_functions.c srcs/read.c srcs/cpy_short.c

OBJ = 	printf.o get_arg.o helpers.o lib_functions.o read.o cpy_short.o


INC = includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) -I $(INC) $(SRC)
	@ar rc $(NAME) $(OBJ) 

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f libft/libft.a
	@/bin/rm -f $(NAME)

re: fclean all
