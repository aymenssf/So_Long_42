/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:19 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/26 16:11:28 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
void init_struct(t_map *map)
{
	map->arr_map = NULL;
	map->player = malloc(sizeof(t_image));
	map->enemy = malloc(sizeof(t_image));
	map->wall = malloc(sizeof(t_image));
	map->collect = malloc(sizeof(t_image));
	map->empty = malloc(sizeof(t_image));
	map->exit = malloc(sizeof(t_image));
	if(!map->player || !map->wall || !map->collect || !map->empty || !map->exit || !map->enemy)
	{
		free(map);
		exit (0);
	}
	map->player->count = 0;
	map->enemy->count = 0;
	map->collect->count = 0;
	map->collect->count_collected = 0;
	map->empty->count = 0;
}

void init_image(t_map *map)
{
    	// map->player->img_1 = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark1.xpm", &map->player->img_x, &map->player->img_y);
    	map->enemy->img = mlx_xpm_file_to_image(map->mlx, "./animations/enemy.xpm", &map->enemy->img_x, &map->enemy->img_y);
    	map->player->img = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark2.xpm", &map->player->img_x, &map->player->img_y);
    	// map->player->img_2 = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark5.xpm", &map->player->img_x, &map->player->img_y);
	map->collect->img = mlx_xpm_file_to_image(map->mlx, "./animations/collect.xpm", &map->collect->img_x, &map->collect->img_y);
	map->empty->img = mlx_xpm_file_to_image(map->mlx, "./animations/ground.xpm", &map->empty->img_x, &map->empty->img_y);
	map->wall->img = mlx_xpm_file_to_image(map->mlx, "./animations/wall.xpm", &map->wall->img_x, &map->wall->img_y);
	map->exit->img = mlx_xpm_file_to_image(map->mlx, "./animations/exit.xpm", &map->exit->img_x, &map->exit->img_y);
}

void	init_map(t_map *map)
{
	map->mlx = mlx_init();
	if(map->mlx == NULL)
		exit(0);
	// map->win = mlx_new_window(map->mlx, (map->row) * PIXEL, (map->col) * PIXEL, "SO_LONG");
	map->win = mlx_new_window(map->mlx, 64 * map->col, 64 * map->row, "SO_LONG");
	if(map->win == NULL)
	{
		free(map->win);
		exit (0);
	}
	init_image(map);
}

