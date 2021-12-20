NAME = megaphone

SOURCES = main.cpp

OBJS = $(SOURCES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra
CC = clang++ -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
