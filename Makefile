##
## EPITECH PROJECT, 2018
## libstring
## File description:
## Builds a lib containing the string
##

override CFLAGS		+=	-W -Wall -Wextra -fPIC -O3
override CPPFLAGS	+=	-I ./include

CC			=	gcc
LD			=	$(CC)

override SRC_DIR 	= 	src/

override SRC			= 	my_malloc.c \
							my_free.c \
							prune_trees.c \
							auxiliary.c \
							tools.c \
							tree_managing.c

override OBJ			=	$(addprefix $(SRC_DIR), $(SRC:.c=.o))

LIB			=	libmy_malloc.so

$(LIB):		$(OBJ)
	$(CC) -shared -o $@ $^

all:		$(LIB)

tests:		$(LIB)
	$(CC) -L./ main.c -lmy_malloc
	LD_LIBRARY_PATH=$(PWD) \
	./a.out

clean:
	@rm -f $(OBJ)
	@rm -f a.out

fclean:		clean
	@echo -e "\e[31;1m(lib) Removing: $(LIB)\e[0m"
	@rm -f $(LIB)

re:		fclean all

.PHONY:	all tests_run clean fclean re
