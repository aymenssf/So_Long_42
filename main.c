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

void read_map(int ac, char **av, t_map *map, int j)
{
    int i;
    char **buffer;
    buffer = NULL;
    check_arg(ac, av);
    i = 0;
    map->row = 0;
    map->col = 0;
    map->fd = open(av[1], O_RDONLY);
    if(map->fd == -1)
        print_error("INDICATES LATER");
	count_line(map);
	map->arr_map = malloc(sizeof(char *) * (map->row));
	close(map->fd);
    map->fd = open(av[1], O_RDONLY);
	while(i < map->row)
		map->arr_map[i++] = get_next_line(map->fd);
	get_next_line(map->fd);
	close(map->fd);
	validatw_wall(map);
	parse_collect(map);
	parse_exit_player(map);

}





/* void	open_file(int argc, char *argv[], t_map *map)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	check_arg(argc, argv, map);
	i = 0;
	map->line = 0;
	map->len = 0;
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		ft_error(map, 3);
	line_counter(map);
	map->tab = malloc(sizeof(char *) * (map->line));
	close(map->fd);
	map->fd = open(argv[1], O_RDONLY);
	while (i < map->line)
		map->tab[i++] = get_next_line(map->fd);
	get_next_line(map->fd);
	close(map->fd);
	parse_door_player(map);
	parse_wall(map);
	parse_item(map);
	tmp = duplicate_map(map);
	check_start(tmp, map);
} */

// void    validate_and_init_game(char *mymap, t_map *map, int i)
// {
//         validate_map(map);
//         check_char(map)
// }

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
