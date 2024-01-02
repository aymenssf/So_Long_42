NAME	= so_long.a
CFLAGS  = -Wall -Werror -Wextra
CC	= cc
SRC	= parsing.c main.c

OBJ 	= $(SRC:.c=.o)
INCLUDES = -I/opt/X11/include -Imlx

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
re:	fclean all
