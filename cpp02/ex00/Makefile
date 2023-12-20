# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 12:06:16 by bfiguet           #+#    #+#              #
#    Updated: 2023/12/19 11:54:18 by bfiguet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		= /bin/bash

NAME		=	ex00
CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			= main.cpp \
			  Fixed.cpp

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