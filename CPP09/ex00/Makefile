CPLUSPLUS = c++

CFLAGS= -Wall -Wextra -Werror -g -std=c++98

SRC= main.cpp BitcoinExchange.cpp

NAME= btc

HEADERS= BitcoinExchange.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPLUSPLUS) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp $(HEADERS)
	$(CPLUSPLUS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re