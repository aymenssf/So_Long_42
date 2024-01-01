/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:41:05 by aassaf            #+#    #+#             */
/*   Updated: 2023/12/31 02:41:05 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    *ft_realloc(void *p, size_t new_size, size_t old_size)
{
        void    *new_p;
        if(p == NULL)
                return (malloc(new_size));
        else if(new_size = 0)
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
}

int     print_error(char *s)
{
        ft_printf("Error\n");
        ft_printf("%s", s);
        exit(0);
}