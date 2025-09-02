CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Iinclude

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HEADER_DIR = include

OBJ_F = obj/

NAME = weapon
OBJ = $(SRC:.cpp=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

all : $(NAME)

HEADER = $(HEADER_DIR)/HumanA.hpp\
		 $(HEADER_DIR)/HumanB.hpp\
		 $(HEADER_DIR)/Weapon.hpp

$(NAME) : $(OBJ_P) $(HEADER)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "✅ successfully created 🏗️!"

$(OBJ_F)%.o:%.cpp | $(OBJ_F) # if it was not exist, create folder
	$(CC) $(FLAGS) -c $< -o $@
	@echo "objects created successfully ✅!"

$(OBJ_F): 
	@mkdir -p $(OBJ_F)

clean :
	rm -f $(OBJ_P)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re