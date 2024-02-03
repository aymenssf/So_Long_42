/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:18:33 by aassaf            #+#    #+#             */
/*   Updated: 2024/02/03 12:44:17 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void destroy_player_anim(t_map *map)
{
    int i;
    i = 0;
    while (i < 35)
    {
        if (!map->player.animations[i])
            mlx_destroy_image(map->mlx, map->player.animations[i]);
        i++;
    }
}

void destroy_collect_anim(t_map *map)
{
    int i;
    i = 0;
    while (i < 49)
    {
        if (!map->collect.animations[i])
            mlx_destroy_image(map->mlx, map->collect.animations[i]);
        i++;
    }
}

void    destroy_img(t_map *map)
{
        destroy_player_anim(map);
        destroy_collect_anim(map);
        mlx_destroy_image(map->mlx, map->wall.animations[0]);
        mlx_destroy_image(map->mlx, map->exit.animations[0]);
        mlx_destroy_image(map->mlx, map->exit.animations[1]);
        mlx_destroy_image(map->mlx, map->empty.animations[0]);
        mlx_destroy_image(map->mlx, map->enemy.animations[0]);
        mlx_loop_end(map->mlx);
        mlx_clear_window(map->mlx, map->win);
        mlx_destroy_window(map->mlx, map->win);
        mlx_destroy_display(map->mlx);
}

int     close_map(t_map *map)
{
        int     i;
        
        i = 0;
        destroy_img(map);
        while(i < map->row)
        {
                free(map->arr_map[i]);
                i++;
        }
        free(map->mlx);
        free(map->arr_map);
        ft_free(map);
        exit (0);
}

int key_handle(int key, t_map *map)
{
        if(key == XK_Escape)
                close_map(map);
        else if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left)
                kill_enemy(map, key);
        move_up(key, map);
        move_down(key, map);
        move_right(key, map);
        move_left(key, map);
        display_counter(map);
        return(0);
}
 
void    event_up(t_map *map, int i, int j)
{
        if (map->arr_map[i - 1][j] == 'M')
                game_over(map);
        if(map->arr_map[i - 1][j] == 'C')
                map->collect.count_collected += 1;
        else if (map->arr_map[i - 1][j] == 'E')
        {
                if(map->collect.count == map->collect.count_collected)
                {       
                        printf("YOU WON !!");
                        close_map(map);
                }
                else
                        return ;              
        }
        map->arr_map[i - 1][j] = 'P';
        map->arr_map[i][j] = '0';
        map->player.count += 1;
        return ;
}

void    event_down(t_map *map, int i, int j)
{
        if (map->arr_map[i + 1][j] == 'M')
                game_over(map);
        if(map->arr_map[i + 1][j] == 'C')
                map->collect.count_collected += 1;

        else if (map->arr_map[i + 1][j] == 'E')
        {
                if(map->collect.count == map->collect.count_collected)
                {       
                        printf("YOU WON !!");
                        close_map(map);
                }
                else
                        return ;          
        }
        map->arr_map[i + 1][j] = 'P';
        map->arr_map[i][j] = '0';
        map->player.count += 1;
        if (map->arr_map[i + 1][j] == 'E')
        {
                if(map->collect.count == map->collect.count_collected)
                {       
                        printf("YOU WON !!");
                        close_map(map);
                }
                else
                        return ;          
        }
        return ;
}

void    event_right(t_map *map, int i, int j)
{
        if (map->arr_map[i][j + 1] == 'M')
                game_over(map);
        if(map->arr_map[i][j + 1] == 'C')
                map->collect.count_collected += 1;
        else if (map->arr_map[i][j + 1] == 'E')
        {
                if(map->collect.count == map->collect.count_collected)
                {       
                        printf("YOU WON !!");
                        close_map(map);
                }
                else
                        return ;              
        }
        map->arr_map[i][j + 1] = 'P';
        map->arr_map[i][j] = '0';
        map->player.count += 1;
        return ;
}

void    event_left(t_map *map, int i, int j)
{
        if (map->arr_map[i][j - 1] == 'M')
                game_over(map);
        if(map->arr_map[i][j - 1] == 'C')
                map->collect.count_collected += 1;
        else if (map->arr_map[i][j - 1] == 'E')
        {
                if(map->collect.count == map->collect.count_collected)
                {       
                        printf("YOU WON !!");
                        close_map(map);
                }
                else
                        return ;              
        }
        map->arr_map[i][j - 1] = 'P';
        map->arr_map[i][j] = '0';
        map->player.count += 1;
        return ;
}