#MAC
# NAME	= so_long
# CFLAGS  = -Wall -Werror -Wextra
# CC	= cc
# SRC	= parsing.c main.c parse_map.c utils.c ft_inits.c ./libft/ft_strlen.c
# GNL = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
# OBJ 	= $(SRC:.c=.o)
# OBJ_GNL 	= $(GNL:.c=.o)
# INCLUDES = -I/opt/X11/include -Imlx

# all:	$(NAME)

# .c.o:
# 	$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@

# MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# $(NAME): $(OBJ) $(OBJ_GNL)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_GNL) $(MLX_FLAGS) -o $(NAME)

# clean:
# 	rm -f $(OBJ) $(OBJ_GNL)

# fclean:	clean
# 	rm -f $(NAME)
# re:	fclean all
# linux

NAME	= so_long
NAMEB	= so_long_bonus
CC	= cc
SRC	= parsing.c main.c parse_map.c utils.c ft_inits.c display.c event.c move.c ./libft/ft_strlen.c 
SRCB	= ./bbonus/parsing_bonus.c ./bbonus/move_enemy.c ./bbonus/collect_sprite.c ./bbonus/main_bonus.c ./bbonus/parse_map_bonus.c ./bbonus/utils_bonus.c ./bbonus/ft_inits_bonus.c ./bbonus/display_bonus.c ./bbonus/event_bonus.c ./bbonus/player_sprite.c ./bbonus/store_img.c ./bbonus/move_bonus.c ./bbonus/handle_bonus.c ./libft/ft_strlen.c ./libft/ft_itoa.c ./libft/ft_strjoin.c
GNL	= ./gnl/get_next_line.c ./gnl/get_next_line_utils.c


%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


OBJ 	= $(SRC:.c=.o)
OBJ_GNL = $(GNL:.c=.o)
OBJB 	= $(SRCB:.c=.o)
all:	$(NAME)


$(NAME): $(OBJ) $(OBJ_GNL)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_GNL) -Lmlx_linux mlx_linux/libmlx.a -lXext -lX11 -lm -lz -g -fsanitize=address -o $(NAME)

$(NAMEB): $(OBJB) $(OBJ_GNL)
	$(CC) $(CFLAGS) $(OBJB) $(OBJ_GNL) -Lmlx_linux mlx_linux/libmlx.a -lXext -lX11 -lm -lz -g -fsanitize=address -o $(NAMEB)
clean:
	rm -f $(OBJ) $(OBJ_GNL) $(OBJB)

fclean:	clean
	rm -f $(NAME) $(NAMEB)

bonus: $(NAMEB)

re:	fclean all
