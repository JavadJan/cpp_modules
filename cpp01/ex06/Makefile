CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I.
HEADER = Harl.cpp

SRC = main.cpp Harl.cpp

NAME = harl
OBJ = $(SRC:.cpp=.o)

all : $(NAME)


$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re