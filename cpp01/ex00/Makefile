CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I. #. means current dir
header = Zombie.hpp
RM = rm -f
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJ = $(SRC:.cpp=.o)

NAME = zombie
all: $(NAME)

$(NAME) : $(OBJ) $(header)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ successfully created 🏗️!"


%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@
	@echo $< "created to " $@
	@echo "successfully creatd objects !" 

clean:
	rm -f $(OBJ)
	@echo "cleaned all objects 🗑️"

fclean: clean
	$(RM) $(NAME)
	@echo "cleaned all 🗑️"

re: fclean $(NAME)

.PHONY: all clean fclean re