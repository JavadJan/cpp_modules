CC = g++
RM = rm -f
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
OBJ = $(SRC:.cpp=.o)

SRC = megaphone.cpp 
NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "successfully created !"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re