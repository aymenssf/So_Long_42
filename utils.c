/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:41:05 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/17 10:33:23 by aassaf           ###   ########.fr       */
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

void count_line(t_map *map)
{
    char *buff;
    int curr_len;

    map->col = 0;
    map->row = 0;

    while ((buff = get_next_line(map->fd)) != NULL) {
        curr_len = ft_strlen(buff);
        if (curr_len > 0 && buff[curr_len - 1] == '\n')
            curr_len--;
        if (curr_len > map->col)
            map->col = curr_len;
        free(buff);
        map->row++;
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
