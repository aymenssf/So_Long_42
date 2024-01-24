/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:43:39 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/24 11:59:25 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_display_asst(t_map *map, int i, int j)
{
        if(map->arr_map[i][j] == '1')
                mlx_put_image_to_window(map->mlx, map->win, map->wall->img, j * 64, i * 64);
        else if (map->arr_map[i][j] == '0')
                mlx_put_image_to_window(map->mlx, map->win, map->empty->img, j * 64, i * 64);
        else if (map->arr_map[i][j] == 'P')
                mlx_put_image_to_window(map->mlx, map->win, map->player->img, j * 64, i * 64);
        else if (map->arr_map[i][j] == 'C')
                mlx_put_image_to_window(map->mlx, map->win, map->collect->img, j * 64, i * 64);
        else if (map->arr_map[i][j] == 'E')
                mlx_put_image_to_window(map->mlx, map->win, map->exit->img, j * 64, i * 64);

}

void    display_asset(t_map *map)
{
        int     i;
        int     j;
        
        i = 0;
        while(i < map->row)
        {
                j = 0;
                while(j < map->col)
                {
                        ft_display_asst(map, i, j);
                        j++;
                }
                i++;
        }
}

void	display_counter(t_map *map)
{
    printf("\n******************** STATISTICS *******************\n\n");
    printf("Total number of items on the map: %d\n", map->collect->count);
    printf("Total moves made by player so far: %d\n", map->player->count);
    printf("Total items collected by the player: %d\n", map->collect->count_collected);
    printf("\n***************************************************\n\n");
}