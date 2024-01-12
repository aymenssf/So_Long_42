/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:41:05 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/12 11:51:11 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void *ft_realloc(void *p, size_t new_size, size_t old_size)
{
        void    *new_p;
        new_p = NULL;
        if(p == NULL)
                return (malloc(new_size));
        else if(new_size == 0)
        {
                free(p);
                return (NULL);
        }
        else
                new_p = malloc(new_p);
        if(!new_p)
                return (NULL);
        ft_memcpy(new_p, p, old_size);
        free(p);
        return (new_p);
} */

void    count_line(t_map *map)
{
        char *buff;

        buff = get_next_line(map->fd);
        if(buff == 0)
                print_error("Error in map");
        map->col = ft_strlen(buff);
        while(buff != NULL)
        {
                free(buff);
                map->row++;
                buff = get_next_line(map->fd);
                if(buff == NULL)
                        free(buff);
        }
}

void free_tmp(char **tmp, t_map *map)
{
        int i;

        i = 0;
        while(i < map->row)
        {
                free(tmp[i]);
                i++;
        }
        free(tmp);
}

int     print_error(char *s)
{
        printf("Error\n");
        printf("%s", s);
        exit(0);
}
