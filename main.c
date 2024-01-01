/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 02:40:44 by aassaf            #+#    #+#             */
/*   Updated: 2023/12/31 02:40:44 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
        int fd;
        char *buffer;
        fd = open("map.ber", O_RDONLY);
        buffer = get_next_line(fd);
        while(buffer)
        {
                ft_printf("%s\n", buffer);
                free(buffer);
                buffer = get_next_line(fd);
        }
}
