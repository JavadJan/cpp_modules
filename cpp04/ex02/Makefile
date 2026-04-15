CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

SRC_F = src/

SRC = main.cpp AAnimal.cpp Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
H = include/

Header = $(H)AAnimal.hpp\
		 $(H)Cat.hpp\
		 $(H)Dog.hpp\
		 $(H)WrongAnimal.hpp\
		 $(H)WrongCat.hpp\
		 $(H)Brain.hpp


NAME = animal
OBJ_F = obj/

OBJ = $(SRC:.cpp=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

all : $(NAME)


$(NAME) : $(OBJ_P) $(Header)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

$(OBJ_F)%.o:$(SRC_F)%.cpp | $(OBJ_F) # if it was not exist, create folder
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