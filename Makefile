CC		= clang++
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp
SRCS2	= test.cpp
OBJ		= $(SRCS:.cpp=.o)
OBJ2	= $(SRCS2:.cpp=.o)
OUT		= main_out.txt
OUT2	= test_out.txt

NAME	= containers
NAME2	= containers2


%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)

clean:
	$(RM) $(OBJ) $(OBJ2)

fclean: clean
	$(RM) $(NAME) $(NAME2) $(OUT) $(OUT2)

re: fclean $(NAME) $(NAME2)

run:
	./$(NAME) 
	./$(NAME2)

test:
	diff $(OUT) $(OUT2)


.PHONY: all clean fclean re
