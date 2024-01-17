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

void fd_error(t_map *map)
{
        if(map->fd == -1)
                print_error("Invalid map");
}

void read_map_helper(t_map *map, int line_number) {
    char *line;
	line = get_next_line(map->fd);
    if (!line) {
        print_error("Unexpected end of file or read error.");
    }
    size_t len;
	len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }
    map->arr_map[line_number] = line;
}
void print_map(char **map, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
void read_map(int argc, char **argv, t_map *map)
{
    int i;
	// int j;
    char **buffer;
    buffer = NULL;
    check_arg(argc, argv);
    i = 0;
    map->row = 0;
    map->col = 0;
    map->fd = open(argv[1], O_RDONLY);
	fd_error(map);
	count_line(map);
	map->arr_map = malloc(sizeof(char *) * (map->row));
	close(map->fd);
    map->fd = open(argv[1], O_RDONLY);
	fd_error(map);
	while(i < map->row)
		map->arr_map[i++] = get_next_line(map->fd);
	get_next_line(map->fd);
	close(map->fd);
	// printf("%d", map->col);
	// printf("%d\n", map->row);
	validate_wall(map);
	parse_collect(map);
	parse_exit_player(map);
	print_map(map->arr_map, map->row, map->col);
	printf("\n");
	buffer = duplicate_map(map);
	check_start(buffer, map);
	print_map(map->arr_map, map->row, map->col);

}

// void    validate_and_init_game(char *mymap, t_map *map, int i)
// {
//         validate_map(map);
//         check_char(map)
// }

int main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	// void	*img;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if(!map)
		return(0);
	init_struct(map);
	read_map(argc, argv, map);
	init_map(map);
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "first window!");
	// img = mlx_new_image(mlx, 1920, 1080);
	// mlx_loop(mlx);
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
