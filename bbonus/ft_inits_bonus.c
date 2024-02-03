/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:19 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/03 12:26:09 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
void init_struct(t_map *map)
{
	init_blocks__img(map, 64, 64);
	init_player_sprite_img(map, 64, 64);
	init_collect_sprite_img(map, 64, 64);
}

void	init_map(t_map *map)
{
	map->mlx = mlx_init();
	if(map->mlx == NULL)
		exit(0);
	map->win = mlx_new_window(map->mlx, 64 * map->col, 64 * map->row, "SO_LONG");
	if(map->win == NULL)
	{
		free(map->win);
		exit (0);
	}
}

