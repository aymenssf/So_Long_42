/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:19 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/29 12:13:09 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
void init_struct(t_map *map)
{
	// int i;
	
	// map->img->arr_img = (void **) malloc (6 * sizeof (void *));
	// i = 0;
	// while (i < 5)
	// 	map->img->arr_img[i++] = (void **) malloc (1 * sizeof (void *));
	// map->img->arr_img[i++] = (void **) malloc (12 * sizeof (void *));
	init_blocks__img(map, 64, 64);
	init_player_sprite_img(map, 64, 64);
	// map->player->count = 0;
	// map->collect.count = 0;
	// map->collect.count_collected = 0;
	// map->empty->count = 0;
}

// void init_img_player(t_map *map)
// {
//     map->player->num_frm = 12;
//     map->player->curr_frm = 0;
// 	printf("%d", map->player->num_frm);
//     for (int frame = 0; frame < map->player->num_frm; frame++)
//     {
//         char frame_path[50];
//         memset(frame_path, 0, sizeof(frame_path));
//         strcpy(frame_path, "./animations/player/shark");
//         // char frame_number[2];
//         char *frame_number = ft_itoa(frame + 1);
// 	strcat(frame_path, frame_number);
//         strcat(frame_path, ".xpm");
//         map->player->animation_frames[frame] = mlx_xpm_file_to_image(map->mlx, frame_path, &map->player->img_x, &map->player->img_y);
//     }

// }

// void init_image(t_map *map)
// {
// 	// map->player->img = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark1.xpm", &map->player->img_x, &map->player->img_y);
// 	// map->player->img_1 = mlx_xpm_file_to_image(map->mlx, "./animations/player/sharkup.xpm", &map->player->img_x, &map->player->img_y);
// 	// map->player->img_2 = mlx_xpm_file_to_image(map->mlx, "./animations/player/sharkup2.xpm", &map->player->img_x, &map->player->img_y);
// 	map->enemy->img = mlx_xpm_file_to_image(map->mlx, "./assets/enem.xpm", &map->enemy->img_x, &map->enemy->img_y);
// 	map->collect.img = mlx_xpm_file_to_image(map->mlx, "./assets/collect.xpm", &map->collect.img_x, &map->collect.img_y);
// 	map->empty->img = mlx_xpm_file_to_image(map->mlx, "./assets/ground.xpm", &map->empty->img_x, &map->empty->img_y);
// 	map->wall->img = mlx_xpm_file_to_image(map->mlx, "./assets/wall.xpm", &map->wall->img_x, &map->wall->img_y);
// 	map->exit->img = mlx_xpm_file_to_image(map->mlx, "./assets/exit.xpm", &map->exit->img_x, &map->exit->img_y);
// }

void	init_map(t_map *map)
{
	map->mlx = mlx_init();
	if(map->mlx == NULL)
		exit(0);
	printf("col => %d\n",map->col);
	map->win = mlx_new_window(map->mlx, 64 * map->col, 64 * map->row, "SO_LONG");
	if(map->win == NULL)
	{
		free(map->win);
		exit (0);
	}
	// init_image(map);
	// init_img_player(map);
}

