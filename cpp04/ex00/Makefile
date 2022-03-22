NAME = Animal

SOURCES = main.cpp \
Animal.cpp \
Dog.cpp \
Cat.cpp \
WrongAnimal.cpp \
WrongCat.cpp \

HEADER_FILES = Animal.hpp \
Cat.hpp \
Dog.hpp \
WrongAnimal.hpp \
WrongCat.hpp \

OBJS = $(SOURCES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra
CC = clang++ -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES)
	@$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
