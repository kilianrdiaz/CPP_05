NAME    = bureaucrat

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

INC_DIR = inc
SRC_DIR = src

SRCS    = $(SRC_DIR)/Bureaucrat.cpp \
          $(SRC_DIR)/main.cpp

OBJS    = $(SRCS:.cpp=.o)

%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re