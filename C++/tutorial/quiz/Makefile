CC = g++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
OBJ = $(SRC:.cpp=.o)

NAME = quiz
SRC	= Quiz.cpp

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "✅ created successfully!"

clean:
	$(RM) $(OBJ)

fclean : clean 
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re