NAME	= so_long.a
CFLAGS  = -Wall -Werror -Wextra
CC	= cc
SRC	= 

OBJ 	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
re:	fclean all
