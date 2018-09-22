# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acakste <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 19:35:06 by acakste           #+#    #+#              #
#    Updated: 2018/09/21 21:36:08 by acakste          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c
OBJ = *.o
FLAGS = -c -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
