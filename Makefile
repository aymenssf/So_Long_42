NAME	= so_long
CFLAGS  = -Wall -Werror -Wextra
CC	= cc
SRC	= parsing.c main.c parse_map.c utils.c ft_inits.c ft_strlen.c get_next_line.c get_next_line_utils.c

OBJ 	= $(SRC:.c=.o)
INCLUDES = -I/opt/X11/include -Imlx

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
re:	fclean all
