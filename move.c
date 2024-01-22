/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:18:36 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/22 17:51:30 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(int key, t_map *map)
{
        int i;
        int j;

        if (key != 119)
                return ;       
        i = 0;
        while(i < map->row)
        {
                j = 0;
                while(j < map->col)
                {
                        if((map->arr_map[i][j] == 'P') && (map->arr_map[i - 1][j] != '1'))
                                event_up(map, i, j);
                        j++;
                }
                i++;
        }
}
void    move_down(int key, t_map *map)
{
        int i;
        int j;

        if (key != 115)
                return ;        
        i = 0;
        while(i < map->row)
        {
                j = 0;
                while(j < map->col)
                {
                        if((map->arr_map[i][j] == 'P') && (map->arr_map[i + 1][j] != '1'))
                        {
                                event_down(map, i, j);
                                return ;
                        }        
                        j++;
                }
                i++;
        }
        return ;
}
void    move_right(int key, t_map *map)
{
        int i;
        int j;

        if (key != 100)
                return ;       
        i = 0;
        while(i < map->row)
        {
                j = 0;
                while(j < map->col)
                {
                        if((map->arr_map[i][j] == 'P') && (map->arr_map[i][j + 1] != '1'))
                        {
                                event_right(map, i, j);
                                return ;
                        }
                        j++;
                }
                i++;
        }
}

void    move_left(int key, t_map *map)
{
        int i;
        int j;
        
        if (key != 97)
                return ;
        i = 0;
        while(i < map->row)
        {
                j = 0;
                while(j < map->col)
                {
                        if((map->arr_map[i][j] == 'P') && (map->arr_map[i][j - 1] != '1'))
                                event_left(map, i, j);
                        j++;
                }
                i++;
        }
}