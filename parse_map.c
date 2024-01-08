/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:55:57 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/08 18:43:43 by aassaf           ###   ########.fr       */
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
