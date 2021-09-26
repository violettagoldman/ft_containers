NAME=ft_containers
FLAGS=-Wall -Wextra -Werror -std=c++98
CC = clang++
ifeq ($(D), 1)
    FLAGS += -g3 -fsanitize=address
endif

OS = $(shell uname -s)
ifeq ($(OS), Linux)
	TICK = \342\234\224
else
	TICK = \xE2\x9C\x94
endif

all: $(NAME)

CONTAINERS = ${wildcard containers/**.hpp}
TESTS = ${wildcard tests/**.cpp}
TESTS += ${wildcard tests/*/*.cpp}

$(NAME): $(CONTAINERS) $(TESTS)
	@$(CC) $(FLAGS) $(TESTS) main.cpp -o $(NAME) -I./containers -I./tests -I./tests/Vector -I./tests/Stack -I./tests/Map
	@echo "\033[32;1m$(NAME) by Violetta Goldman is done ${TICK}          "

clean:
	@rm -rf $(NAME)
	@echo "\033[32;1mCleaned ${TICK}\033[0m"

fclean: clean
	@rm -rf $(NAME).dSYM
	@echo "\033[32;1mForced cleaned ${TICK}\033[0m"

re: fclean all

.PHONY: clean fclean all re