NAME = span
CPP = c++
RM = rm -rf
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98

SRC = main.cpp\
		Span.cpp\


OBJ = $(SRC:.cpp=.o)

Reset = \033[0m
G = \033[32m
R = \033[31m
Y = \033[33m
blink = \033[6;7;1;31m

all: $(NAME)

$(NAME): $(OBJ)
		@echo "----------------------Compilation of $(NAME)-----------------------"
		@$(CPP) $(CXXFLAGS) -o $(NAME) $(OBJ)
		@echo "-------------------------------------------------------------------"
		@echo "$(G) ✅ $(NAME) compiled successfully!$(Reset)"

val: re
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME)

clean:
		@echo " 🧹 Cleaning up object files...$(Reset)"
		@$(RM) $(OBJ)
		@echo "$(G) ✅ Cleaned Obejct Files!$(Reset)"

fclean: clean
		@echo " 🧹 Cleaning up executable..."
		@$(RM) $(NAME)
		@echo "$(G) ✅ $(NAME) has been removed !$(Reset)"

re: fclean all

.PHONY: all clean fclean re val
