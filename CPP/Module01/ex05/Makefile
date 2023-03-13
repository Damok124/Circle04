# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 22:22:05 by zharzi            #+#    #+#              #
#    Updated: 2023/03/13 10:03:56 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Harl

SRCS = \
Harl.cpp \
main.cpp

OBJ = $(SRCS:.cpp=.o)

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -I. -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
