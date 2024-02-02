/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:55:19 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/01 21:29:28 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
void init_struct(t_map *map)
{
	// map->enemy.curr_direction = 1;
	init_blocks__img(map, 64, 64);
	init_player_sprite_img(map, 64, 64);
	init_collect_sprite_img(map, 64, 64);
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

