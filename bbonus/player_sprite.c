/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:17:43 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/28 21:59:38 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void player_sprite(void ***img, t_map *map, int w, int h)
{
    static int frame = 0;

    mlx_put_image_to_window(map->mlx, map->win, img[1][frame], w, h);

    frame++;
    if (frame >= 12)
        frame = 0;
}
