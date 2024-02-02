/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:55:57 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/01 19:29:12 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long_bonus.h"

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
                while(j < map->col)
                {
                        tmp[i][j] = map->arr_map[i][j];
                        j++;
                }
                i++;
        }
        return(tmp);
}

void free_map_and_road(char **tmp, t_map *map, int x, int y)
{
        int i;

        if(tmp[x][y] == 'E' || tmp[x][y] == 'C')
        {
                free_tmp(tmp, map);
                i = 0;
                if(i < map->row)
                {
                        free(map->arr_map[i]);
                        i++;
                }
                free(map->arr_map);
                hdl_error(map, 3);
        }
}

void	check_start(char **tmp, t_map *map)
{
       int      x;
       int      y;

       x = 0;
       	// print_map(tmp, map->row, map->col);
       ft_flood_fill(tmp, map);
       	// print_map(tmp, map->row, map->col);
       while(x < map->row)
       {
                y = 0;
                while(y < map->col)
                {
                        free_map_and_road(tmp, map, x, y);
                        y++;
                }
                x++;
       }
       free_tmp(tmp, map);
}


void flood_fill(char **tmp, int x, int y)
{
        if(tmp[x][y] == 'E' || tmp[x][y] == 'F')
        {
                if(tmp[x][y] == 'E')
                        tmp[x][y] = 'F';
                return ;
        }
        else if(tmp[x][y] != '1')
        {
                tmp[x][y] = 'F';
                flood_fill(tmp, x + 1, y);
                flood_fill(tmp, x - 1, y);
                flood_fill(tmp, x, y + 1);
                flood_fill(tmp, x, y - 1);
        }
}

void	ft_flood_fill(char **tmp, t_map *map)
{
       int      x;
       int      y;

       x = 0;
       while(x < map->row)
       {
                y = 0;
                while(y < map->col)
                {
                        if(tmp[x][y] == 'P')
                                flood_fill(tmp, x, y);
                        y++;
                }
                x++;
       }
}
