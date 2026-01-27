CC = c++
FLAGS = -Wall -Wextra -Werror -Iinclude -std=c++98

H = include/
HEADER = $(H)Bureaucrat.hpp $(H)Form.hpp

SRC_F = src/

OBJ_F = obj/

SRC = main.cpp Bureaucrat.cpp Form.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

NAME = bureaucrat

all : $(NAME)

$(NAME): $(OBJ_P) #$(HEADER)
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

#If any header file changes, the affected object files will be recompiled.
#The object files depend on both their .cpp sources and the headers.
$(OBJ_F)%.o:$(SRC_F)%.cpp $(HEADER)| $(OBJ_F)
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

#$(NAME): $(OBJ_P) $(HEADER)
#    $(CC) $(FLAGS) $(OBJ_P) -o $(NAME)

#$(OBJ_F)%.o: $(SRC_F)%.cpp | $(OBJ_F)
#    $(CC) $(FLAGS) -c $< -o $@

#Here the executable depends directly on the headers ($(HEADER)).

#The object files depend only on their .cpp sources, not on headers.

#Problem: If a header changes, the object files will not be rebuilt, because they don’t list headers as prerequisites.

#Make will only see that the executable depends on headers, so it will rerun the link step — but linking alone won’t help if the objects are stale.

#Result: you can end up with an executable that doesn’t reflect header changes. ❌