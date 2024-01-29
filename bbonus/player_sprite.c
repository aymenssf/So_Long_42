/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:17:43 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/29 19:21:03 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void player_sprite(t_map *map, int w, int h)
{
    static int frame = 0;

    mlx_put_image_to_window(map->mlx, map->win, map->player.animations[frame % 9], w, h);
    usleep(50000);

    frame++;
    if (frame >= 100)
        frame = 0;
}
