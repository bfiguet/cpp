# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 12:06:16 by bfiguet           #+#    #+#              #
#    Updated: 2023/12/18 12:51:07 by bfiguet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		= /bin/bash

NAME		=	ex03
CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			= main.cpp \
			  Weapon.cpp \
			  HumanA.cpp \
			  HumanB.cpp	  	

OBJ			= $(SRC:.cpp=.o)
.o:.cpp
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(OBJ) $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re