CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -f
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJ = $(SRC:.cpp=.o)

NAME = zombie
all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ successfully created 🏗️!"

clean:
	rm -f $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re