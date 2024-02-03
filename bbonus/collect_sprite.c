/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:28:19 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/03 11:01:18 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void collect_sprite(t_map *map, int x, int y)
{
    static int current_frame = 0;
    static int frame_delay = 0;
    frame_delay++;
    if (frame_delay >= 130)
    {
        current_frame++;
        frame_delay = 0;
    }

    if (current_frame >= 50)
        current_frame = 0;
    mlx_put_image_to_window(map->mlx, map->win, map->collect.animations[current_frame], x, y);
}