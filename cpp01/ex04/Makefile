CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp
NAME = copy
OBJ = $(SRC:.cpp=.o)

all : $(NAME)


$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@
	@echo "successfully obj created ✅!"

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re