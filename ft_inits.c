/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:19 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/03 14:32:31 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_image(t_map *map)
{
	map->player.img = mlx_xpm_file_to_image(map->mlx, "./assets/shark.xpm", &map->player.img_x, &map->player.img_y);
	map->collect.img = mlx_xpm_file_to_image(map->mlx, "./assets/collect.xpm", &map->collect.img_x, &map->collect.img_y);
	map->empty.img = mlx_xpm_file_to_image(map->mlx, "./assets/ground.xpm", &map->empty.img_x, &map->empty.img_y);
	map->wall.img = mlx_xpm_file_to_image(map->mlx, "./assets/wall.xpm", &map->wall.img_x, &map->wall.img_y);
	map->exit.img = mlx_xpm_file_to_image(map->mlx, "./assets/exit.xpm", &map->exit.img_x, &map->exit.img_y);
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

