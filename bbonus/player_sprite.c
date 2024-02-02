/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:17:43 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/01 22:16:53 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void player_sprite(t_map *map, int w, int h, int direction)
{
    static int frame = 0;

    int frame_start = direction * 9;
    int frame_end = frame_start + 8;

    mlx_put_image_to_window(map->mlx, map->win, map->player.animations[frame % (frame_end - frame_start + 1) + frame_start], w, h);
    usleep(50000);
    frame++;
    if (frame >= 100)
        frame = 0;
}
