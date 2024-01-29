/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:21:14 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/29 19:19:29 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_blocks__img(t_map *map, int w, int h)
{
	printf("mlx pinter => %p\n",map->mlx);
        map->empty.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/ground.xpm", &w, &h);
        map->wall.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/wall.xpm", &w, &h);
        map->collect.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/collect.xpm", &w, &h);
        map->exit.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/exit.xpm", &w, &h);
        map->enemy.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/enemy.xpm", &w, &h);
}

void	init_player_sprite_img(t_map *map, int w, int h)
{
	map->player.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark1.xpm", &w, &h);
	map->player.animations[1] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark2.xpm", &w, &h);
	map->player.animations[2] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark3.xpm", &w, &h);
	map->player.animations[3] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark4.xpm", &w, &h);
	map->player.animations[4] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark5.xpm", &w, &h);
	map->player.animations[5] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark6.xpm", &w, &h);
	map->player.animations[6] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark7.xpm", &w, &h);
	map->player.animations[7] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark8.xpm", &w, &h);
	map->player.animations[8] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark9.xpm", &w, &h);
}