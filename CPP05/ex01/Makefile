C++ = c++

C++FLAGS = -g -Wall -Werror -Wextra -std=c++98

NAME = Form_up,maggots!

SRC = main.cpp Bureaucrat.cpp Form.cpp

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