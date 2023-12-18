# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 12:13:52 by bfiguet           #+#    #+#              #
#    Updated: 2023/12/08 18:15:05 by bfiguet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		= /bin/bash

NAME		=	megaphone
CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			= main.cpp	

all:		$(NAME)

$(NAME):	$(SRC)
		$(CC) $(CFLAGS) -o $@ $^

clean:
		

fclean:		clean
		rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
