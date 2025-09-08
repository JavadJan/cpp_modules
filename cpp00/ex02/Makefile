CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC	=	tests.cpp Account.cpp
NAME = acount


OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo " successfully created !"

%.o:%.cpp
	$(CC) &(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re