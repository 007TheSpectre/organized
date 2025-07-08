##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

MAKE	=	make

all:
	$(MAKE) -C my/
	$(MAKE) -C linked_list/
	cp shell/libshell libshell.a

clean:
	$(MAKE) -C my/ clean
	$(MAKE) -C linked_list/ clean

fclean:	clean
	$(MAKE) -C my/ fclean
	$(MAKE) -C linked_list/ fclean
	rm libshell.a
