NAME    = concreteForms

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

SRCS    = $(SRC_DIR)/Bureaucrat.cpp \
          $(SRC_DIR)/AForm.cpp \
          $(SRC_DIR)/ShrubberyCreationForm.cpp \
          $(SRC_DIR)/RobotomyRequestForm.cpp \
          $(SRC_DIR)/PresidentialPardonForm.cpp \
          $(SRC_DIR)/main.cpp

INCS	=	$(INC_DIR)/Bureaucrat.hpp \
			$(INC_DIR)/AForm.hpp \
			$(INC_DIR)/ShrubberyCreationForm.hpp \
			$(INC_DIR)/RobotomyRequestForm.hpp \
			$(INC_DIR)/PresidentialPardonForm.hpp

OBJS    = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCS) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re