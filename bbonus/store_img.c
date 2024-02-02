/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:21:14 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/01 22:31:22 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_blocks__img(t_map *map, int w, int h)
{
	printf("mlx pinter => %p\n",map->mlx);
        map->empty.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/ground.xpm", &w, &h);
        map->wall.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/wall.xpm", &w, &h);
        map->collect.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/collect.xpm", &w, &h);
        map->exit.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/exit.xpm", &w, &h);
        map->exit.animations[1] = mlx_xpm_file_to_image(map->mlx, "./animations/exit_opened.xpm", &w, &h);
        map->enemy.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/enemy.xpm", &w, &h);
}

void	init_player_sprite_img(t_map *map, int w, int h)
{
	map->player.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark1.xpm", &w, &h);
	map->player.animations[1] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark2.xpm", &w, &h);
	map->player.animations[2] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark3.xpm", &w, &h);
	map->player.animations[3] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark4.xpm", &w, &h);
	map->player.animations[4] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark5.xpm", &w, &h);
	map->player.animations[5] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark6.xpm", &w, &h);
	map->player.animations[6] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark7.xpm", &w, &h);
	map->player.animations[7] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark8.xpm", &w, &h);
	map->player.animations[8] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark9.xpm", &w, &h);
	map->player.animations[9] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark10.xpm", &w, &h);
	map->player.animations[10] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark11.xpm", &w, &h);
	map->player.animations[11] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark12.xpm", &w, &h);
	map->player.animations[12] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark13.xpm", &w, &h);
	map->player.animations[13] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark14.xpm", &w, &h);
	map->player.animations[14] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark15.xpm", &w, &h);
	map->player.animations[15] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark16.xpm", &w, &h);
	map->player.animations[16] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark17.xpm", &w, &h);
	map->player.animations[17] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark18.xpm", &w, &h);
	map->player.animations[18] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark19.xpm", &w, &h);
	map->player.animations[19] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark20.xpm", &w, &h);
	map->player.animations[20] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark21.xpm", &w, &h);
	map->player.animations[21] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark22.xpm", &w, &h);
	map->player.animations[22] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark23.xpm", &w, &h);
	map->player.animations[23] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark24.xpm", &w, &h);
	map->player.animations[24] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark25.xpm", &w, &h);
	map->player.animations[25] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark26.xpm", &w, &h);
	map->player.animations[26] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark27.xpm", &w, &h);
	map->player.animations[27] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark28.xpm", &w, &h);
	map->player.animations[28] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark29.xpm", &w, &h);
	map->player.animations[29] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark30.xpm", &w, &h);
	map->player.animations[30] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark31.xpm", &w, &h);
	map->player.animations[31] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark32.xpm", &w, &h);
	map->player.animations[32] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark33.xpm", &w, &h);
	map->player.animations[33] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark34.xpm", &w, &h);
	map->player.animations[34] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark35.xpm", &w, &h);
	map->player.animations[35] = mlx_xpm_file_to_image(map->mlx, "./animations/player/shark36.xpm", &w, &h);
}
// void init_collect_sprite_img(t_map *map, int w, int h)
// {
//     map->collect.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect1.xpm", &w, &h);
//     map->collect.animations[1] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect2.xpm", &w, &h);
//     map->collect.animations[2] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect3.xpm", &w, &h);
//     map->collect.animations[3] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect4.xpm", &w, &h);
//     map->collect.animations[4] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect5.xpm", &w, &h);
//     map->collect.animations[5] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect6.xpm", &w, &h);
//     map->collect.animations[6] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect7.xpm", &w, &h);
//     map->collect.animations[7] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect8.xpm", &w, &h);
//     map->collect.animations[8] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect9.xpm", &w, &h);
// //     map->collect.animations[9] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect10.xpm", &w, &h);
// //     map->collect.animations[10] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect11.xpm", &w, &h);
// //     map->collect.animations[11] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect12.xpm", &w, &h);
// //     map->collect.animations[12] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect13.xpm", &w, &h);
// //     map->collect.animations[13] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect14.xpm", &w, &h);
// //     map->collect.animations[14] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect15.xpm", &w, &h);
// //     map->collect.animations[15] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect16.xpm", &w, &h);
// //     map->collect.animations[16] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect17.xpm", &w, &h);
// //     map->collect.animations[17] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect18.xpm", &w, &h);
// }
void init_collect_sprite_img(t_map *map, int w, int h)
{
    map->collect.animations[0] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect1.xpm", &w, &h);
    map->collect.animations[1] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect2.xpm", &w, &h);
    map->collect.animations[2] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect3.xpm", &w, &h);
    map->collect.animations[3] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect4.xpm", &w, &h);
    map->collect.animations[4] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect5.xpm", &w, &h);
    map->collect.animations[5] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect6.xpm", &w, &h);
    map->collect.animations[6] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect7.xpm", &w, &h);
    map->collect.animations[7] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect8.xpm", &w, &h);
    map->collect.animations[8] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect9.xpm", &w, &h);
    map->collect.animations[9] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect10.xpm", &w, &h);
    map->collect.animations[10] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect11.xpm", &w, &h);
    map->collect.animations[11] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect12.xpm", &w, &h);
    map->collect.animations[12] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect13.xpm", &w, &h);
    map->collect.animations[13] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect14.xpm", &w, &h);
    map->collect.animations[14] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect15.xpm", &w, &h);
    map->collect.animations[15] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect16.xpm", &w, &h);
    map->collect.animations[16] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect17.xpm", &w, &h);
    map->collect.animations[17] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect18.xpm", &w, &h);
    map->collect.animations[18] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect19.xpm", &w, &h);
    map->collect.animations[19] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect20.xpm", &w, &h);
    map->collect.animations[20] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect21.xpm", &w, &h);
    map->collect.animations[21] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect22.xpm", &w, &h);
    map->collect.animations[22] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect23.xpm", &w, &h);
    map->collect.animations[23] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect24.xpm", &w, &h);
    map->collect.animations[24] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect25.xpm", &w, &h);
    map->collect.animations[25] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect26.xpm", &w, &h);
    map->collect.animations[26] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect27.xpm", &w, &h);
    map->collect.animations[27] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect28.xpm", &w, &h);
    map->collect.animations[28] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect29.xpm", &w, &h);
    map->collect.animations[29] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect30.xpm", &w, &h);
    map->collect.animations[30] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect31.xpm", &w, &h);
    map->collect.animations[31] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect32.xpm", &w, &h);
    map->collect.animations[32] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect33.xpm", &w, &h);
    map->collect.animations[33] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect34.xpm", &w, &h);
    map->collect.animations[34] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect35.xpm", &w, &h);
    map->collect.animations[35] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect36.xpm", &w, &h);
    map->collect.animations[36] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect37.xpm", &w, &h);
    map->collect.animations[37] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect38.xpm", &w, &h);
    map->collect.animations[38] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect39.xpm", &w, &h);
    map->collect.animations[39] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect40.xpm", &w, &h);
    map->collect.animations[40] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect41.xpm", &w, &h);
    map->collect.animations[41] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect42.xpm", &w, &h);
    map->collect.animations[42] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect43.xpm", &w, &h);
    map->collect.animations[43] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect44.xpm", &w, &h);
    map->collect.animations[44] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect45.xpm", &w, &h);
    map->collect.animations[45] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect46.xpm", &w, &h);
    map->collect.animations[46] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect47.xpm", &w, &h);
    map->collect.animations[47] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect48.xpm", &w, &h);
    map->collect.animations[48] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect49.xpm", &w, &h);
    map->collect.animations[49] = mlx_xpm_file_to_image(map->mlx, "./animations/collect/collect50.xpm", &w, &h);
}