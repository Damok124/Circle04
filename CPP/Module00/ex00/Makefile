NAME = megaphone

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) megaphone.cpp -o $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
