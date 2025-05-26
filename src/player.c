/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:39:45 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/26 11:57:48 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void player_forward(t_game *game)
{
    game->player_y -= 1;
    game->player_dir = 3;
}

void player_back(t_game *game)
{
    game->player_y += 1;
    game->player_dir = 0;
}

void player_left(t_game *game)
{
    game->player_x -= 1;
    game->player_dir = 1;
}

void player_right(t_game *game)
{
    game->player_x += 1;
    game->player_dir = 2;
}

void find_player_pos(t_data *m)
{
    int y;
    int x;
    char **map;
    
    map = m->map;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                m->game.player_x = x;
                m->game.player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}