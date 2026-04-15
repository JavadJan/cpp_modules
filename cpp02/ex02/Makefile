CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -I.

SRC = main.cpp Fixed.cpp

NAME = fixed

HEDAER = Fixed.hpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)


$(NAME) : $(OBJ) $(HEDAER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@
	@echo "successfully created : $@ ✅"
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re