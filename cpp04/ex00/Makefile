# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 12:06:16 by bfiguet           #+#    #+#              #
#    Updated: 2023/12/21 19:05:01 by bfiguet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		= /bin/bash

NAME		=	ex00
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -g -std=c++98

INC_PATH	= ./inc/
INC_PATH	= -I $(INC_PATH)

SRC_PATH	= ./src/
SRC			= $(wildcard $(SRC_PATH)*.cpp)

OBJ_PATH	= ./obj/
OBJ			= $(SRC:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

all:		$(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $@ $^ $(INC)

clean:
		rm -rf $(OBJ_PATH)

fclean:		clean
		rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re