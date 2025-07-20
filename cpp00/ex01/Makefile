CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC	=	PhoneBook.cpp Contact.cpp add_search.cpp get_entry.cpp
NAME = phonebook


OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo " successfully created !"

clean:
	rm -f $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re