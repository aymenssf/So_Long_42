/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:30:40 by aassaf            #+#    #+#             */
/*   Updated: 2023/12/31 02:30:40 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_char(t_map *map, int i, int j)
{
        if(map->arr_map[i][j] != '0' && map->arr_map[i][j] != '1'
         && map->arr_map[i][j] != 'C' && map->arr_map[i][j] != 'E'
         && map->arr_map[i][j] != 'P')
                printerror("Invalid map\n");
}

void    validate_map(t_map *map, int i, int j)
{
        if(map->player < 1 || map->exit < 1 || map->collect < 1)
        {
                print_error("Map must contain at least one player, one exit and one collectible.\n");
                return;        
        }
        if(map->player > 1 || map->exit > 1 || map->collect > 1)
        {
                print_error("Map must not contain duplicate player, one exit and one collectible.\n");
                return;        
        i = 0;
        j = 0;
        while(i < map->row)
        {
                while(j < map->col)
                {
                        if(i == 0 || i == map->row - 1 || j == 0 || j == map->col - 1)
                        {
                                if(map->arr_map[i][j] != 1)
                                {
                                        print_error("Map must be surrounded by walls.\n");
                                        return;
                                }
                        }
                        j++;
                }
                i++;
        }
        ft_printf("Map is valid !\n");
}