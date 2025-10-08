CC  	= c++
FLAG = -Wall -Wextra -Werror -std=c++98 -pedantic

App	= Application/
Net = Networking/

OBJ_F 	= obj/
#LIBFT	= libft.a
NAME	= webserver

SRC		= main.cpp SimpleSocket.cpp load_env.cpp




OBJ = $(SRC:.cpp=.o)
OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

all : $(NAME)

$(NAME) : $(OBJ_P) # create executeing file by its object dependencies
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_P)
	@echo "✅ created successfully! 🛠️ 🏗️"

$(OBJ_F)%.o:$(App)%.cpp  | $(OBJ_F) #create object bit its dependencies
	$(CC) $(FLAGS) -c $< -o $@ -I.
	@echo "compiling:  $<"
	
$(OBJ_F)%.o:$(Net)%.cpp  | $(OBJ_F) #create object bit its dependencies
	$(CC) $(FLAGS) -c $< -o $@ -I.
	@echo "compiling:  $<"

$(OBJ_F): 
	@mkdir -p $(OBJ_F)

leaks: $(NAME)
	@$(VALGRIND) ./$(NAME)

clean:
	rm -f $(OBJ_P)

fclean: clean
	rm -f $(NAME)
	@echo "removed objs files successfuly"

re : fclean all

.PHONY: all clean fclean re