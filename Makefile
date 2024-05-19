##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## abc
##

SRC = $(shell find src/ -type f -name "*.c")

SRC_NO_MAIN = $(shell find src/ -type f -name "*.c" ! -name "main.c")

SRC_TESTS = $(shell find tests/ -type f -name "*.c")

OBJ = $(SRC:src/%.c=obj/%.o)

NAME = crame_ton_pc

CFLAGS = -Wall -Wextra -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: clean fclean all
