##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC	=	gcc

NAME	=	liblinklist.a

SRC	=	linked_list_manage.c \
		my_add_in_sorted_list.c \
		my_apply_on_matching_nodes.c \
		my_apply_on_nodes.c \
		my_concat_list.c \
		my_delete_nodes.c \
		my_find_node.c \
		my_list_size.c \
		my_merge.c \
		my_params_to_list.c \
		my_rev_list.c \
		my_sort_list.c \


OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	cp $(NAME) ../
	cp linked_list.h ../../include/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
