CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Iinclude
SRC	=	PhoneBook.cpp Contact.cpp add_search.cpp read_in.cpp
NAME = phonebook

HEADER_PHONE = include/PhoneBook.hpp
HEADER_CONTACT = include/Contact.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER_CONTACT) $(HEADER_PHONE)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo " successfully created ✅✅✅"

%.o:%.cpp #here I used explicit creation of obj
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "removed all obj ❌❌❌"

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re