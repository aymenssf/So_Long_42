/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:29:02 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/24 11:29:02 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void fd_error(t_map *map)
{
        if(map->fd == -1)
                print_error("Invalid map");
}

void read_map(int argc, char **argv, t_map *map)
{
    int i;
	// int j;
    char **buffer;
    buffer = NULL;
    check_arg(argc, argv, map);
    i = 0;
    map->row = 0;
    map->col = 0;
    map->fd = open(argv[1], O_RDONLY);
	fd_error(map);
	count_line(map);
	if (map->row == 0)
	{
		print_error("Error: Map file is empty.\n");
		exit(1);
	}
	map->arr_map = malloc(sizeof(char *) * (map->row));
	if (map->arr_map == NULL)
	{
		close(map->fd);
        	print_error("Memory allocation failed.\n");
    	}
	close(map->fd);
    map->fd = open(argv[1], O_RDONLY);
	fd_error(map);
	while(i < map->row)
		map->arr_map[i++] = get_next_line(map->fd);
	get_next_line(map->fd);
	close(map->fd);
	parse_exit_player(map);
	validate_wall(map);
	parse_collect(map);
	buffer = duplicate_map(map);
	check_start(buffer, map);
}

// void	read_map(int argc, char *argv[], t_map *map)
// {
// 	int		i;
// 	char	**tmp;

// 	tmp = NULL;
// 	check_arg(argc, argv, map);
// 	i = 0;
// 	map->row = 0;
// 	map->col = 0;
// 	map->fd = open(argv[1], O_RDONLY);
// 	if (map->fd == -1)
// 		hdl_error(map, 3);
// 	count_line(map);
// 	map->arr_map = malloc(sizeof(char *) * (map->row));
// 	close(map->fd);
// 	map->fd = open(argv[1], O_RDONLY);
// 	while (i < map->row)
// 		map->arr_map[i++] = get_next_line(map->fd);
// 	get_next_line(map->fd);
// 	close(map->fd);
// 	parse_exit_player(map);
// 	validate_wall(map);
// 	parse_collect(map);
// 	tmp = duplicate_map(map);
// 	check_start(tmp, map);
// }

int main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if(!map)
		return(0);
	init_struct(map);
	read_map(argc, argv, map);
	init_map(map);
	display_asset(map);
	mlx_hook(map->win, KeyPress, KeyPressMask, &key_handle, map);
	mlx_hook(map->win, 17, 1L << 0, *close_map, map);
	mlx_loop(map->mlx);
	close_map(map);
	return (0);
}

// int	main(int argc, char*argv[])
// {
// 	t_map	*map;

// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 		return (0);
// 	init_struct(map);
// 	open_file(argc, argv, map);
// 	init_map(map);
// 	display_image(map);
// 	mlx_hook(map->win, KeyPress, KeyPressMask, &handle_key, map);
// 	mlx_hook(map->win, 17, 1L << 0, *ft_close, map);
// 	mlx_loop(map->mlx);
// 	ft_close(map);
// 	return (0);
// }
