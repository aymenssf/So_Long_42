/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:42:08 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/02 16:08:05 by aassaf           ###   ########.fr       */
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
typedef	struct s_collect
{
	int count;
}	t_collect;

typedef struct s_player
{
	int x;
	int y;

}	t_player;

typedef struct s_map
{
	int player;
	t_collect *collect;
	int wall;
	int empty;
	int exit;
	int row;
	int col;
	char **arr_map;
}	t_map;


void    validate_map(t_map *map);
void read_map(char *av, t_map);
int parse_wall(t_map *map, int i, int j);
void    *ft_realloc(void *p, size_t new_size, size_t old_size);
int     print_error(char *s);
char	*get_next_line(int fd);
int	ft_printf(const char *s, ...);
void    check_arg(int ac, char **av);
// void    check_arg(int ac, char **av, t_map *map);
#endif
