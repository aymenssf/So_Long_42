/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:36:14 by aassaf            #+#    #+#             */
/*   Updated: 2024/01/28 16:58:38 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_map *map)
{
        printf("\n\t\33[91m#############\33[0m\n");
        printf("\t\33[91m- GAME OVER -\33[0m\n");
        printf("\t\33[91m#############\33[0m\n\n");
        printf("You lose !\n");
	close_map(map);
}
void update_animation(t_image *image)
{
    image->curr_frm = (image->curr_frm + 1) % image->num_frm;

//     void *current_frame = image->animation_frames[image->curr_frm];
}