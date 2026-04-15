CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I.
RM = rm -f
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

HEADER = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

NAME = zombie
all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ successfully created 🏗️!"

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re