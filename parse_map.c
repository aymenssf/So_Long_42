/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:55:57 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/11 22:21:36 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	**duplicate_map(t_map *map)
{
        char **tmp;
        int     i;
        int     j;

        tmp = malloc(sizeof(char *) * map->row);
        if(!tmp)
                return NULL;
        i = 0;
        while(i < map->row)
        {
                tmp[i] = malloc(sizeof(char *) * map->col);
                i++;
        }
        i = 0;
        while(i < map->row)
        {
                j = 0;
                while(i < map->col)
                {
                        tmp[i][j] = map->arr_map[i][j];
                        j++;
                }
                i++;
        }
        return(tmp);
}

void	ft_flood_fill(char **tmp, t_map *map)
{
        
}

void flood_fill(t_map *map, int x, int y, char curr_pos, char replace)
{
        if(x < 0 || x >= map->row || y < 0 || y >= map->col)
                return;
        if(map->arr_map[x][y] != curr_pos)
                return;
        map->arr_map[x][y] = replace;
        flood_fill(map, x + 1, y, curr_pos, replace);
        flood_fill(map, x - 1, y, curr_pos, replace);
        flood_fill(map, x, y + 1, curr_pos, replace);
        flood_fill(map, x, y - 1, curr_pos, replace);
}
