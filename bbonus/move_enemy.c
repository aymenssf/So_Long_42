/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:23:53 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/02 13:01:55 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"


// void move_enemy_v(t_map *map, int i, int j) {
//     int next_i = i + map->enemy.curr_direction;

//     if (next_i >= 0 && next_i < map->row && map->arr_map[next_i][j] != '1') {
//         map->arr_map[next_i][j] = 'M';
//         map->arr_map[i][j] = '0';
//     } else {
//         map->enemy.curr_direction = -map->enemy.curr_direction;
//     }
// }
// void enemy_patrol(t_map *map, unsigned int frame) {
//         map->enemy.curr_direction = 1;
//     if (frame % 20 == 0) {
//         for (int i = 0; i < map->row; i++) {
//             for (int j = 0; j < map->col; j++) {
//                 if (map->arr_map[i][j] == 'M') {
//                     if (map->enemy.curr_direction == 1) {
//                         move_enemy_h(map, i, j);
//                     } else {
//                         move_enemy_v(map, i, j);
//                     }
//                 }
//             }
//         }
//     }
// }

// void move_enemy_h(t_map *map, int i, int j) {
//     int next_j = j + map->enemy.curr_direction; 

//     if (next_j >= 0 && next_j < map->col && map->arr_map[i][next_j] != '1') {
//         map->arr_map[i][next_j] = 'M';
//         map->arr_map[i][j] = '0';
//     } else {
//         map->enemy.curr_direction = -map->enemy.curr_direction;
//     }
// }
void move_enemy_h(t_map *map, int i, int *j, int *curr_direc_h)
{
    int next_j = *j + *curr_direc_h;

    if (next_j >= 0 && next_j < map->col && map->arr_map[i][next_j] != '1')
    {
        map->arr_map[i][*j] = '0';
        *j = next_j;
        map->arr_map[i][*j] = 'M';
    }
    else 
    {
        *curr_direc_h = -(*curr_direc_h);
        next_j = *j + *curr_direc_h;
        if (next_j >= 0 && next_j < map->col && map->arr_map[i][next_j] != '1') 
        {
            map->arr_map[i][*j] = '0';
            *j = next_j;
            map->arr_map[i][*j] = 'M';
        }
    }
}

// void enemy_patrol(t_map *map, int *curr_direc_h)
// {
//     int i;
//     int j;
    
//     i = 0;
//     while (i < map->row)
//     {
//         j = 0;
//         while (j < map->col)
//         {
//             if (map->arr_map[i][j] == 'M')
//             {
//                 if ((j + 1 < map->col && map->arr_map[i][j + 1] == '1') ||
//                     (j - 1 >= 0 && map->arr_map[i][j - 1] == '1') ||
//                     (j + 1 < map->col && map->arr_map[i][j + 1] == 'C') ||
//                     (j - 1 >= 0 && map->arr_map[i][j - 1] == 'C'))
//                     *curr_direc_h = -(*curr_direc_h);
//                 if ((j - 1 >= 0 && map->arr_map[i][j - 1] == 'P') || (j - 1 >= 0 && map->arr_map[i][j + 1] == 'P'))
//                     game_over(map);
//                 move_enemy_h(map, i, &j, curr_direc_h);
//             }
//             j++;
//         }
//         i++;
//         // printf("*curr_direc_h ---> %d\n", *curr_direc_h);
//     }
// }

void enemy_patrol(t_map *map, int *curr_direc_h)
{
    int i;
    int j;
    
    i = 0;
    while (i < map->row)
    {
        j = 0;
        while (j < map->col)
        {
            if (map->arr_map[i][j] == 'M')
            {
                if ((j + *curr_direc_h < map->col && map->arr_map[i][j + *curr_direc_h] == '1') ||
                    (j + *curr_direc_h < map->col && map->arr_map[i][j + *curr_direc_h] == 'C') ||
                    (j + *curr_direc_h < map->col && map->arr_map[i][j + *curr_direc_h] == 'E'))
                    *curr_direc_h = -(*curr_direc_h);
                if ((j + *curr_direc_h >= 0 && map->arr_map[i][j + *curr_direc_h] == 'P'))
                    game_over(map);
                move_enemy_h(map, i, &j, curr_direc_h);
            }
            j++;
        }
        i++;
        // printf("*curr_direc_h ---> %d\n", *curr_direc_h);
    }
}