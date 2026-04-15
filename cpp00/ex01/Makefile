CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Iinclude
SRC	=	PhoneBook.cpp Contact.cpp add_search.cpp read_in.cpp
NAME = phonebook

HEADER_C = include/Contact.hpp
HEADER_PH = include/PhoneBook.hpp


OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER_C) $(HEADER_PH)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo " successfully created !"

%.o:%.cpp #here I used explicit creation of obj
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re