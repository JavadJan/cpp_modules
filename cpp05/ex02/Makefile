CC = c++
FLAGS = -Wall -Wextra -Werror -Iinclude -std=c++98

H = include/
HEADER = $(H)Bureaucrat.hpp $(H)AForm.hpp $(H)ShrubberyCreationForm.hpp\
		$(H)RobotomyRequestForm.hpp $(H)PresidentialPardonForm.hpp

SRC_F = src/

OBJ_F = obj/

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)

OBJ_P = $(addprefix $(OBJ_F), $(OBJ))

NAME = bureaucrat

all : $(NAME)

$(NAME): $(OBJ_P) 
	$(CC) $(FLAGS) $(OBJ_P) -o $(NAME)
	@echo "✅ successfully created 🏗️ 🛠️!"

$(OBJ_F)%.o:$(SRC_F)%.cpp $(HEADER) | $(OBJ_F)
	$(CC) $(FLAGS) -c $< -o $@
	@echo "successfully $@ created ✅"

$(OBJ_F): 
	@mkdir -p $(OBJ_F)

clean :
	rm -f $(OBJ_P)
	rm -f home_shrubbery

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re