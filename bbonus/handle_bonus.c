/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:36:14 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/01 09:24:06 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_map *map)
{
        printf("\n\t\33[91m#############\33[0m\n");
        printf("\t\33[91m- GAME OVER -\33[0m\n");
        printf("\t\33[91m#############\33[0m\n\n");
        printf("You lose !\n");
	close_map(map);
}

void kill_enemy(t_map *map, int key)
{
        int i;
        int j;
        
        i = 0;
        while (i < map->row)
        {
                j = 0;
                while (j < map->col)
                {
                        if (map->arr_map[i][j] == 'P')
                        {
                                if (key == XK_Up && i - 1 >= 0 && map->arr_map[i - 1][j] == 'M')
                                        map->arr_map[i - 1][j] = '0';
                                else if (key == XK_Down && i + 1 < map->row && map->arr_map[i + 1][j] == 'M')
                                        map->arr_map[i + 1][j] = '0';
                                else if (key == XK_Right && j + 1 < map->col && map->arr_map[i][j + 1] == 'M')
                                        map->arr_map[i][j + 1] = '0';
                                else if (key == XK_Left && j - 1 >= 0 && map->arr_map[i][j - 1] == 'M')
                                        map->arr_map[i][j - 1] = '0';
                                return;
                        }
                        j++;
                }
                i++;
    }
}
