# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 12:14:03 by bfiguet           #+#    #+#              #
#    Updated: 2023/12/08 16:19:41 by bfiguet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		= /bin/bash

NAME		=	phonebook
CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRC			= Contact.cpp \
			  Phonebook.cpp		  	

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
