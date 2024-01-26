/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:41:05 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/26 16:19:19 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
    int line_is_empty;

    map->col = 0;
    map->row = 0;
    line_is_empty = 1;

    while ((buff = get_next_line(map->fd)) != NULL) {
        curr_len = ft_strlen(buff);
        if (curr_len > 0 && buff[curr_len - 1] == '\n')
            curr_len--;
        if (curr_len > 0)
            line_is_empty = 0;
        if (curr_len > map->col)
            map->col = curr_len;
        free(buff);
        map->row++;
    }

    if (line_is_empty == 1) {
        print_error("Empy Map OR Contains empty lines.\n");
    }
}
// void	count_line(t_map *map)
// {
// 	char	*ret;

// 	ret = get_next_line(map->fd);
// 	if (ret == 0)
// 		hdl_error(map,2);
// 	map->col = ft_strlen(ret);
// 	while (ret != NULL)
// 	{
// 		free(ret);
// 		map->row++;
// 		ret = get_next_line(map->fd);
// 		if (ret == NULL)
// 			free(ret);
// 	}
// }
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
void ft_free(t_map *map)
{
        free(map->player);
        free(map->enemy);
        free(map->wall);
        free(map->exit);
        free(map->collect);
        free(map->empty);
        free(map);
}

void hdl_error(t_map *map, int flag)
{
        int i;
        
        i = 0;
        printf("Error\n");
        if(flag == 0)
                printf("Argument is invalid!\n");
        else if (flag == 1)
                printf("Argument format is invalid!\n");
        else if (flag == 2)
        {
                printf("Map is invalid!\n");
                while(i < map->row)
                {
                        free(map->arr_map[i]);
                        i++;
                }
                free(map->arr_map);
        }
        else if (flag == 3)
                printf("No path available to exit or items\n");
        ft_free(map);
        exit (0);
}
int     print_error(char *s)
{
        printf("Error\n");
        printf("%s", s);
        exit(0);
}
