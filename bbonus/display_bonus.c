/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:43:39 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/31 14:34:29 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
void    ft_display_asst(t_map *map, int i, int j)
{
        if(map->arr_map[i][j] == '1')
                mlx_put_image_to_window(map->mlx, map->win, map->wall.animations[0], j * 64, i * 64);
        else if (map->arr_map[i][j] == '0')
                mlx_put_image_to_window(map->mlx, map->win, map->empty.animations[0], j * 64, i * 64);
        else if (map->arr_map[i][j] == 'P')
        {        
                mlx_put_image_to_window(map->mlx, map->win, map->player.animations[0], j * 64, i * 64);
                player_sprite(map, j * 64, i * 64, map->player.curr_direction);
        }
        else if (map->arr_map[i][j] == 'C')
                mlx_put_image_to_window(map->mlx, map->win, map->collect.animations[0], j * 64, i * 64);
        else if (map->arr_map[i][j] == 'E')
        {
                if(map->collect.count == map->collect.count_collected)
                        mlx_put_image_to_window(map->mlx, map->win, map->exit.animations[1], j * 64, i * 64);       
                else
                        mlx_put_image_to_window(map->mlx, map->win, map->exit.animations[0], j * 64, i * 64);
        }        
        else if (map->arr_map[i][j] == 'M')
                mlx_put_image_to_window(map->mlx, map->win, map->enemy.animations[0], j * 64, i * 64);

}

int    display_asset(t_map *map)
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
        return(0);
}

void	display_counter(t_map *map)
{
    printf("\n******************** STATISTICS *******************\n\n");
    printf("Total number of items on the map: %d\n", map->collect.count);
    printf("Total moves made by player so far: %d\n", map->player.count);
    printf("Total items collected by the player: %d\n", map->collect.count_collected);
    printf("\n***************************************************\n\n");
}