NAME = interface

SOURCES = main.cpp \
AMateria.cpp \
Character.cpp \
Cure.cpp \
Ice.cpp \
MateriaSource.cpp 

HEADER_FILES = AMateria.hpp \
Character.hpp \
Cure.hpp \
Ice.hpp \
MateriaSource.hpp \
IMateriaSource.hpp \
ICharacter.hpp 


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
