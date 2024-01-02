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

void read_map(char *av, t_map map)
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

void    validate_and_init_game(char *mymap, t_map map, int i)
{

}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "first window!");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
}
