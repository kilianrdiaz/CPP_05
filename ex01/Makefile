NAME    = form

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

SRCS    = $(SRC_DIR)/Bureaucrat.cpp \
          $(SRC_DIR)/Form.cpp \
          $(SRC_DIR)/main.cpp

INCS	= $(INC_DIR)/Bureaucrat.hpp \
		  $(INC_DIR)/Form.hpp

OBJS    = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCS) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re