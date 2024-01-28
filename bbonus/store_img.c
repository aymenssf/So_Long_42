/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:21:14 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/28 22:23:29 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_blocks__img(void ***img, t_map *map, int w, int h)
{
        img[0][0] = mlx_xpm_file_to_image(map->mlx, "./animations/ground.xpm", &w, &h);
        img[2][0] = mlx_xpm_file_to_image(map->mlx, "./animations/wall.xpm", &w, &h);
        img[4][0] = mlx_xpm_file_to_image(map->mlx, "./animations/collect.xpm", &w, &h);
        img[5][0] = mlx_xpm_file_to_image(map->mlx, "./animations/exit.xpm", &w, &h);
        img[6][0] = mlx_xpm_file_to_image(map->mlx, "./animations/enemy.xpm", &w, &h);
}

void	init_player_sprite_img(void ***img, t_map *map, int w, int h)
{
	img[1][0] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark1.xpm", &w, &h);
	img[1][1] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark2.xpm", &w, &h);
	img[1][2] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark3.xpm", &w, &h);
	img[1][3] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark4.xpm", &w, &h);
	img[1][4] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark5.xpm", &w, &h);
	img[1][5] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark6.xpm", &w, &h);
	img[1][6] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark7.xpm", &w, &h);
	img[1][7] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark8.xpm", &w, &h);
	img[1][8] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark9.xpm", &w, &h);
	img[1][9] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark10.xpm", &w, &h);
	img[1][10] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark11.xpm", &w, &h);
	img[1][11] = mlx_xpm_file_to_image(map->mlx, "./animation/player/shark12.xpm", &w, &h);
}