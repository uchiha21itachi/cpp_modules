NAME = Animal

SOURCES = main.cpp \
AAnimal.cpp \
Dog.cpp \
Cat.cpp \
WrongAnimal.cpp \
WrongCat.cpp \
Brain.cpp \

HEADER_FILES = AAnimal.hpp \
Cat.hpp \
Dog.hpp \
WrongAnimal.hpp \
WrongCat.hpp \
Brain.hpp \

OBJS = $(SOURCES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra
CC = c++ -std=c++98

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
