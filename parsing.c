/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:30:40 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/24 12:25:01 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_char(t_map *map, int i, int j)
{
        if(map->arr_map[i][j] != '0' && map->arr_map[i][j] != '1'
         && map->arr_map[i][j] != 'C' && map->arr_map[i][j] != 'E'
         && map->arr_map[i][j] != 'P')
                hdl_error(map, 1);
}
// void    validate_map(t_map map, int fd)
// {

// }
void    check_arg(int argc, char **argv, t_map *map)
{
        int     i;
        if(argc != 2)
        {
                hdl_error(map, 0);
                return;
        }
        i = ft_strlen(argv[1]) - 1;
        if((argv[1][i] != 'r') ||( argv[1][i - 1] != 'e') || (argv[1][i - 2] != 'b')
        || argv[1][i - 3] != '.' || ft_strlen(argv[1]) < 5)
                hdl_error(map, 2);
}

// void    validate_map(t_map *map)
// {
//         if(map->player->count < 1 || map->exit->count < 1 || map->collect->count < 1)
//         {
//                 print_error("Map must contain at least one player, \
//                 one exit and one collectible.\n");
//                 return;
//         }
//         if(map->player->count > 1 || map->exit->count > 1)
//         {
//                 print_error("Map must not contain duplicate player, \
//                 duplicate exit\n");
//                 return;
//         }
//         printf("Map is valid !\n");
// }
int validate_wall(t_map *map)
{
    int i;

    i = 0;
    while (i < map->col)
    {
        if (map->arr_map[0][i] != '1' || map->arr_map[map->row - 1][i] != '1')
        {
            print_error("Map must be surrounded by walls.\n");
            return (1);
        }
        i++;
    }
    i = 1;
    while (i < map->row - 1)
    {
        if (map->arr_map[i][0] != '1' || map->arr_map[i][map->col - 1] != '1')
        {
            print_error("Map must be surrounded by walls.\n");
            return (1);
        }
        i++;
    }
    return (0);
}
//check if the map is surrounded with walls
// int validate_wall(t_map *map)
// {
//         int     i;
//         int     j;
//         // i = 0;
//         // while(i < map->row)
//         // {
//         //         if (map->col != (int)ft_strlen(map->arr_map[i]))
//         //                 print_error("Map must be surrounded by walls.\n");
//         //         i++;
//         // }
//         i = 0;
//         while(i < map->row)
//         {
//                 j = 0;
//                 while(j < map->col)
//                 {
//                         if((i == 0 || i == map->row - 1 || j == 0 || j == map->col - 1) && map->arr_map[i][j] != '1')
//                         {
//                                 print_error("Map must be surrounded by walls.\n");
//                                 return (1);
//                         }
//                         j++;
//                 }
//                 i++;
//         }
//         return (0);
// }

int     parse_exit_player(t_map *map)
{
        int     i;
        int     j;
        int count_exit;
        int count_player;
        i = 0;
        count_exit = 0;
        count_player = 0;
        while(i < map->row)
        {
                j = 0;
                while(j < map->col)
                {
                        check_char(map, i, j);
                        if(map->arr_map[i][j] == 'E')
                                count_exit += 1;
                        else if(map->arr_map[i][j] == 'P')
                                count_player += 1;
                        j++;
                }
                i++;
        }
        if(count_exit != 1 || count_player != 1 )
                print_error("Player or exit are different than 1");
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
                        j++;
                }
                i++;
        }
        if(map->collect->count == 0)
                print_error("Collectibles are less than 1");
        return ;
}
