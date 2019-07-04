CXXC=clang++
CXXFLAGS=-Werror -Wextra -Wall -g -Iinclude -std=c++14
SRC=$(wildcard src/*)
NAME=avm
OBJ=$(SRC:src/%.cpp=%.o)

.PHONY: clean fclean all re norm norme debug test norman update

VPATH = src obj includes

$(NAME): $(OBJ)
	$(CXXC) $(CXXFLAGS) -o $(NAME) obj/*
	@echo "$(NAME) build complete!"

all: $(NAME)

%.o: %.cpp
	@mkdir -p obj
	$(CXXC) $(CXXFLAGS) -o obj/$@ -c $<

clean:
	@rm -rf obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all
