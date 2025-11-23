CC = c++
FLAGS = -Wextra -Werror -Wall -Iinclude

NAME = queue

SRC = queue.cpp
SRC_F = src/
OBJ_F = obj/

H = include/
HEADER = $(H)List.hpp

OBJ = $(SRC:.cpp=.o)

#in ./obj/ create the .cpp to .o
OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

all: $(NAME)

$(NAME) : $(OBJ_P)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

$(OBJ_F)%.o:$(SRC_F)%.cpp $(HEADER) | $(OBJ_F) #how make objects 
	$(CC) $(FLAGS) -c $< -o $@
	@echo "successfully $@ created ✅"


$(OBJ_F):
	@mkdir -p $(OBJ_F)

clean :
	rm -f $(OBJ_P)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re