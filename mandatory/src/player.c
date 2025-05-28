/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:39:45 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/28 11:39:17 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void player_forward(t_data *m)
{
    int x = m->game.player_x;
    int y = m->game.player_y;

    if (y > 0 && m->map[y - 1][x] != '1')
    {
        if (m->map[y - 1][x] == 'E' && m->game.collected != m->game.total_collectibles)
            return;
        m->game.player_y -= 1;
        m->game.player_dir = 3;
    }
}

void player_back(t_data *m)
{
    int x = m->game.player_x;
    int y = m->game.player_y;

    if (y + 1 < Y_MAX && m->map[y + 1][x] != '1')
    {
        if (m->map[y + 1][x] == 'E' && m->game.collected != m->game.total_collectibles)
            return ;
        m->game.player_y += 1;
        m->game.player_dir = 0;
    }
}

void player_left(t_data *m)
{
    int x = m->game.player_x;
    int y = m->game.player_y;

    if (x > 0 && m->map[y][x - 1] != '1')
    {
        if (m->map[y][x - 1] == 'E' && m->game.collected != m->game.total_collectibles)
            return ;
        m->game.player_x -= 1;
        m->game.player_dir = 1;
    }
}

void player_right(t_data *m)
{
    int x = m->game.player_x;
    int y = m->game.player_y;

    if (x + 1 < X_MAX && m->map[y][x + 1] != '1')
    {
        if (m->map[y][x + 1] == 'E' && m->game.collected != m->game.total_collectibles)
            return ;
        m->game.player_x += 1;
        m->game.player_dir = 2;
    }
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