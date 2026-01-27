CC = c++
FLAGS = -Wall -Wextra -Werror -Iinclude -std=c++98


H = include/
HEADER = $(H)Data.hpp\
		$(H)Serializer.hpp


NAME = convert

OBJ_F = obj/
SRC_F = src/

SRC = main.cpp Serializer.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

all: $(NAME)

$(NAME) : $(OBJ_P) 
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

$(OBJ_F)%.o:$(SRC_F)%.cpp $(HEADER) | $(OBJ_F)
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