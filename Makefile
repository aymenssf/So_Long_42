# NAME	= so_long
# CFLAGS  = -Wall -Werror -Wextra
# CC	= CC
# SRC	= parsing.c main.c parse_map.c utils.c ft_inits.c ft_strlen.c ./gnl/get_next_line.c ./gnl/	get_next_line_utils.c

# OBJ 	= $(SRC:.c=.o)
# INCLUDES = -I/opt/X11/include -Imlx

# all:	$(NAME)

# .c.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@

# MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) -o $(NAME)

# clean:
# 	rm -f $(OBJ)

# fclean:	clean
# 	rm -f $(NAME)
# re:	fclean all
# linux

NAME	= so_long
CC	= cc
SRC	= parsing.c main.c parse_map.c utils.c ft_inits.c ./libft/ft_strlen.c 
GNL	= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c


%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


OBJ 	= $(SRC:.c=.o)
OBJ_GNL = $(GNL:.c=.o)
all:	$(NAME)


$(NAME): $(OBJ)
	clang $(CFLAGS) $(OBJ) $(OBJ_GNL) -Lmlx_linux mlx_linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)
clean:
	rm -f $(OBJ) $(OBJ_GNL)

fclean:	clean
	rm -f $(NAME)

re:	fclean all