C++ = c++

C++FLAGS = -g -Wall -Werror -Wextra -std=c++98

NAME = No,you_need_form_28B,not_28C...

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

HEADERS = Bureaucrat.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(C++FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(C++) $(C++FLAGS) -c $< -o $@

clean:
	rm -f $(SRC:.cpp=.o)

fclean : clean
	rm -f $(NAME)

re: fclean all