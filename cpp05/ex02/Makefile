NAME = Bureaucrat

SOURCES = main.cpp \
Bureaucrat.cpp \
Form.cpp \
PresidentialPardonForm.cpp \
RobotomyRequestForm.cpp \
ShrubberyCreationForm.cpp \


HEADER_FILES = Bureaucrat.hpp \
Form.hpp \
PresidentialPardonForm.hpp \
RobotomyRequestForm.hpp \
ShrubberyCreationForm.hpp \

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
