/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:30:40 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/12 17:44:41 by aassaf           ###   ########.fr       */
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
// void    validate_map(t_map map, int fd)
// {

// }
void    check_arg(int argc, char **argv)
{
        int     i;
        if(argc != 2)
        {
                print_error("Argument is invalid!\n");
                return;
        }
        i = ft_strlen(argv[1]) - 1;
        if((argv[1][i] != 'r') ||( argv[1][i - 1] != 'e') || (argv[1][i - 2] != 'b')
        || argv[1][i - 3] != '.' || ft_strlen(argv[1]) < 5)
                print_error("Invalid map\n");
}

void    validate_map(t_map *map)
{
        if(map->player->count < 1 || map->exit->count < 1 || map->collect->count < 1)
        {
                print_error("Map must contain at least one player, \
                one exit and one collectible.\n");
                return;
        }
        if(map->player->count > 1 || map->exit->count > 1)
        {
                print_error("Map must not contain duplicate player, \
                duplicate exit\n");
                return;
        }
        printf("Map is valid !\n");
}

// int parse_wall(t_map *map, int i, int j)
// {
//         i = 0;
//         while(i < map->col)
//         {
//                 if(map->arr_map[0][i] != 1 || map->arr_map[map->row - 1][i] != 1)
//                         print_error("Map must be surrounded by walls.\n");
//                 i++;
//         }
//         i = 1;
//         while(i < map->row)
//         {
//                 if()
//         }
//         return (0);
// }

//check if the map is surrounded with walls
int validate_wall(t_map *map)
{
        int     i;
        int     j;

        i = 0;
        j = 0;
        if (map->col != (int)ft_strlen(map->arr_map[i]))
                print_error("Map must be surrounded by walls.\n");
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

int     parse_exit_player(t_map *map)
{
        int     i;
        int     j;

        i = 0;

        while(i < map->row)
        {
                j = 0;
                check_char(map, i, j);
                if(map->arr_map[i][j] == 'E')
                        map->exit->count += 1;
                else if(map->arr_map[i][j] == 'P')
                        map->player->count += 1;
        }
        if(map->exit->count != 1 || map->player->count != 1 )
                print_error("Player or exit are more than 1");
        return (0);
}

void     parse_collect(t_map *map)
{
        int     i;
        int     j;

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
