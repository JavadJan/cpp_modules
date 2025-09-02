CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I.

SRC = main.cpp Zombie.cpp zombieHorde.cpp
header = Zombie.hpp
NAME = horde
OBJ = $(SRC:.cpp=.o)

all : $(NAME)


$(NAME) : $(OBJ) $(header)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ successfully created 🏗️!"

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re