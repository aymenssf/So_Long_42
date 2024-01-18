/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:19 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/18 19:47:38 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void init_struct(t_map *map)
{
	map->arr_map = NULL;
	map->player = malloc(sizeof(t_image));
	map->wall = malloc(sizeof(t_image));
	map->collect = malloc(sizeof(t_image));
	map->empty = malloc(sizeof(t_image));
	map->exit = malloc(sizeof(t_image));
	if(!map->player || !map->wall || !map->collect || !map->empty || !map->exit )
	{
		free(map);
		exit (0);
	}
	map->player->count = 0;
	map->collect->count = 0;
	map->empty->count = 0;
}

// void init_image(t_map *map)
// {
// 	map->player
// }

void	init_map(t_map *map)
{
	map->mlx = mlx_init();
	if(map->mlx == NULL)
		exit(0);
	map->win = mlx_new_window(map->mlx, (map->row) * PIXEL, (map->col) * PIXEL, "SO_LONG");
	if(map->win == NULL)
	{
		free(map->win);
		exit (0);
	}
	//still init images
}

