CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I.

SRC = main.cpp Harl.cpp
HEADER = Harl.hpp
NAME = harl
OBJ = $(SRC:.cpp=.o)

all : $(NAME)


$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re