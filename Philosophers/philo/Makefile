# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 13:40:41 by zharzi            #+#    #+#              #
#    Updated: 2022/12/12 15:31:11 by zharzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libphilo.a

BINARY = philo

SRCSDIR = ./srcs/

SRCS = \
${SRCSDIR}test.c

HEADERDIR = includes/

HEADER = philo.h

OBJ = $(SRCS:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

IFLAG = -I$(HEADERDIR)

all : libphilo.a
	$(CC) $(FLAGS) main.c $(IFLAG) -L. -lphilo -o $(BINARY) -lpthread

%.o : %.c
	$(CC) $(FLAGS) $(IFLAG) -o $@ -c $^  -lpthread

libphilo.a : $(OBJ) $(HEADERDIR)$(HEADER)
	ar -rcs $(NAME) $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f $(BINARY)

re : fclean all

.PHONY : all clean fclean re
