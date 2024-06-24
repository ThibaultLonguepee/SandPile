##
## EPITECH PROJECT, 2024
## SandPile
## File description:
## Makefile
##

__RED	:=	\033[0;31m
__GREEN	:=	\033[0;32m
__BOLD	:=	\033[1m
__NC	:=	\033[0m

__NAME	:= sandpile

__SRC	:=	src/main.cpp \
	src/SandPileException.cpp \
	src/Setup.cpp \
	src/Map.cpp \

%.o: %.cpp
	@$(__CXX) -c -o $@ $< $(__CXXFLAGS)

__OBJ = $(__SRC:.cpp=.o)

__CXX	:=	g++

__CXXFLAGS += -Wall -Wextra -Werror -Wpedantic -std=c++20
__CXXFLAGS += -I./include

all: $(__NAME)

DEFAULT: all

COPY_COLLAPSE: __CXXFLAGS += -DCOPY_COLLAPSE
COPY_COLLAPSE: all

SELF_COLLAPSE: __CXXFLAGS += -DSELF_COLLAPSE
SELF_COLLAPSE: all

$(__NAME):	$(__OBJ)
	@printf "$(__GREEN)$(__BOLD)Compilation\n$(__NC)"
	@$(__CXX) -o $(__NAME) $(__OBJ) $(__CXXFLAGS)
	@printf "$(__GREEN)completed successfully.\n$(__NC)"

clean:
	@printf "$(__GREEN)$(__BOLD)Clean\n$(__NC)"
	@rm -f $(__OBJ)
	@printf "$(__GREEN)completed successfully.\n$(__NC)"

fclean: clean
	@printf "$(__GREEN)$(__BOLD)Fclean\n$(__NC)"
	@rm -f $(__NAME)
	@printf "$(__GREEN)completed successfully.\n$(__NC)"

re: fclean all

test:
	@python3 tests/tester.py

.PHONY: all clean fclean re
