/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:18:33 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/20 20:11:43 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    destroy_img(t_map *map)
{
        mlx_destroy_image(map->mlx, map->player->img);
        mlx_destroy_image(map->mlx, map->wall->img);
        mlx_destroy_image(map->mlx, map->exit->img);
        mlx_destroy_image(map->mlx, map->collect->img);
        mlx_destroy_image(map->mlx, map->empty->img);
        mlx_loop_end(map->mlx);
        mlx_destroy_window(map->mlx, map->win);
        mlx_destroy_display(map->mlx);
}
int     close_map(t_map *map)
{
        int i;
        
        i = 0;
        destroy_img(map);
        while(i < map->row)
        {
                free(map->arr_map[i]);
        }
        free(map->mlx);
        free(map->arr_map);
        ft_free(map);
        exit(0);
}

int key_handle(int key, t_map *map)
{
        if(key == XK_Escape)
                close_map(map);
        return(0);
}