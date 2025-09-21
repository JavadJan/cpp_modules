CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
NAME = test
SRC = main.cpp sort_bouble.cpp fill_array.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ created successfully!"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
