/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:42:08 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/24 11:54:23 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 128

# include <X11/keysym.h>
# include <X11/X.h>

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "mlx.h"
# include <stdio.h>

typedef struct s_animation
{
    int i;
    int j;
    int player_status;
} t_animation;

typedef struct s_image
{
	void *animations[50];
	void	*img;
	int img_x;
	int img_y;
	int count;
	int count_collected;
}	t_image;


typedef struct s_map
{
	void *mlx;
	void *win;
	t_image player;
	t_image enemy;
	t_image collect;
	t_image wall;
	t_image empty;
	t_image exit;
	int fd;
	int row;
	int col;
	char **arr_map;
	t_image *img;
}	t_map;

size_t				ft_strlen(const char *s);
void    validate_map(t_map *map);
int validate_wall(t_map *map);
void    *ft_realloc(void *p, size_t new_size, size_t old_size);
void	read_map(int argc, char **argv, t_map *map);
void read_map_helper(t_map *map, int line_number);
int     print_error(char *s);
char	*get_next_line(int fd);
char	**duplicate_map(t_map *map);
void    check_arg(int argc, char **argv, t_map *map);
void init_struct(t_map *map);
char	**duplicate_map(t_map *map);
int     parse_exit_player(t_map *map);
void     parse_collect(t_map *map);
void	init_map(t_map *map);
void flood_fill(char **tmp, int x, int y);
void	ft_flood_fill(char **tmp, t_map *map);
void	check_start(char **tmp, t_map *map);
void free_map_and_road(char **tmp, t_map *map, int x, int y);
void    count_line(t_map *map);
void	free_tmp(char **tmp, t_map *map);
void fd_error(t_map *map);
void hdl_error(t_map *map, int flag);
void    ft_display_asst(t_map *map, int i, int j);
int    display_asset(t_map *map);
void init_img_player(t_map *map);
void update_animation(t_image *image);
void	display_counter(t_map *map);
int key_handle(int key, t_map *map);
int     close_map(t_map *map);
void    destroy_img(t_map *map);
void	ft_free(t_map *map);
void    move_up(int key, t_map *map);
void    move_down(int key, t_map *map);
void    move_right(int key, t_map *map);
void    move_left(int key, t_map *map);
void    event_up(t_map *map, int i, int j);
void    event_down(t_map *map, int i, int j);
void    event_right(t_map *map, int i, int j);
void    event_left(t_map *map, int i, int j);
void	game_over(t_map *map);
void	init_player_sprite_img(t_map *map, int w, int h);
void	init_blocks__img(t_map *map, int w, int h);
void player_sprite(t_map *map, int w, int h);
void free_arr_img(t_map *map, void ***arr_img, int *cols_per_row, int rows);
// void    move_up(int key, t_map *map);
// void    validate_and_init_game(char *mymap, t_map map, int i);
#endif
