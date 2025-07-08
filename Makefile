##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC	=	gcc

MAKE	=	make

NAME	=	organized

SRC_DIR	=	src

OBJ_DIR	=	obj

SRC	=	$(SRC_DIR)/get_order.c \
		$(SRC_DIR)/sort.c \
		$(SRC_DIR)/disp.c \
		$(SRC_DIR)/del.c \
		$(SRC_DIR)/add.c \
		$(SRC_DIR)/main.c \

OBJ	=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Wextra -Iinclude/

LIB_DIR = lib/

LDFLAGS += -Llib/ -lmy -llinklist -lshell

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(OBJ_DIR) $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) -g

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJ)
	-rmdir $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)
	rm -f unit_tests

run: all
	./$(NAME)

re: fclean all

unit_tests: fclean $(NAME)
	gcc tests/*.c -L. -lmy -Iinclude/ -lcriterion -o unit_tests

tests_run: unit_tests
	./unit_tests || true
