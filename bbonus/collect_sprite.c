/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:28:19 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/02 12:55:13 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void collect_sprite(t_map *map, int w, int h)
{
    static int frame = 0;


    mlx_put_image_to_window(map->mlx, map->win, map->player.animations[frame], w, h);
    usleep(50000);
    frame++;
    if (frame >= 100)
        frame = 0;
}