/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:42:08 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/04 18:56:43 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <stdio.h>
typedef struct s_player
{
	int x;
	int y;

}	t_player;

typedef struct s_image
{
	void *img;
	int img_x;
	int img_y;
	int count;
}	t_image;


typedef struct s_map
{
	void *mlx;
	void *win;
	t_image *player;
	t_image *collect;
	t_image *wall;
	t_image *empty;
	t_image *exit;
	int fd;
	int row;
	int col;
	char **arr_map;
}	t_map;


void    validate_map(t_map *map);
int parse_wall(t_map *map, int i, int j);
void    *ft_realloc(void *p, size_t new_size, size_t old_size);
void	read_map(int ac, char **av, t_map *map, int j);
int     print_error(char *s);
char	*get_next_line(int fd);
void    check_arg(int ac, char **av);
void init_struct(t_map *map);
char	**duplicate_map(t_map *map);
int     parse_exit_player(t_map *map);

// void    validate_and_init_game(char *mymap, t_map map, int i);
// void    check_arg(int ac, char **av, t_map *map);
#endif
