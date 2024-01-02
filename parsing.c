/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:30:40 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/02 15:12:15 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_char(t_map *map, int i, int j)
{
        if(map->arr_map[i][j] != '0' && map->arr_map[i][j] != '1'
         && map->arr_map[i][j] != 'C' && map->arr_map[i][j] != 'E'
         && map->arr_map[i][j] != 'P')
                print_error("Invalid map\n");
}

void    check_arg(int ac, char **av)
{
        int     i;
        if(ac != 2)
        {
                print_error("Argument is invalid!\n");
                return;
        }
        i = ft_strlen(av[1]) - 1;
        if((av[1][i] != 'r') ||( av[1][i - 1] != 'e') || (av[1][i - 2] != 'b')
        || av[1][i - 3] != '.' || ft_strlen(av[1]) < 5)
                print_error("Invalid map\n");
}

void    validate_map(t_map *map)
{
        if(map->player < 1 || map->exit < 1 || map->collect->count < 1)
        {
                print_error("Map must contain at least one player, \
                one exit and one collectible.\n");
                return;
        }
        if(map->player > 1 || map->exit > 1 || map->collect->count > 1)
        {
                print_error("Map must not contain duplicate player, \
                one exit and one collectible.\n");
                return;
        }
        ft_printf("Map is valid !\n");
}

int parse_wall(t_map *map, int i, int j)
{
        i = 0;
        while(i < map->row)
        {
                while(j < map->col)
                {
                        j = 0;
                        if(i == 0 || i == map->row - 1 || j == 0 || j == map->col - 1)
                        {
                                if(map->arr_map[i][j] != 1)
                                {
                                        print_error("Map must be surrounded by walls.\n");
                                        return (1);
                                }
                        }
                        j++;
                }
                i++;
        }
        return (0);
}

// int     player_parse_wall(t_map *map)
// {

// }
void     parse_collect(t_map *map, int i, int j)
{
        i = 0;
        while(i < map->row)
        {
                j = 0;
                while(j < map->col)
                {
                        check_char(map, i, j);
                        if(map->arr_map[i][j] == 'C')
                                map->collect->count += 1;
                }
                if(map->collect->count == 0)
                        print_error("Collectibles are less than 1");
        }
}

