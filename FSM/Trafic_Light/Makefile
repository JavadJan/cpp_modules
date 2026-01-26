CC = c++
FLAGS = -Wall -Wextra -Werror

H = ./include
HEADER = $(H)/TraficLight.hpp

NAME = TraficLight

SRC_F = src/
OBJ_F = obj/

SRC = main.cpp TraficLight.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ)) #define a varaible of path e.g., ./obj/main.o


all: $(NAME)

$(NAME) : $(OBJ_P) 
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

$(OBJ_F)%.o:$(SRC_F)%.cpp $(HEADER) | $(OBJ_F) #how make objects 
	$(CC) $(FLAGS) -c $< -o $@
	@echo "successfully $@ linked $< ✅"

$(OBJ_F):
	@mkdir -p $(OBJ_F)

clean :
	rm -f $(OBJ_P)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re