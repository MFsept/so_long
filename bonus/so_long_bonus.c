/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:03:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/28 15:36:59 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int main(void)
{
    int     fd;
    char    **map;
    t_data  m;
    // t_sprites sprites;0
    // t_game  game;

    fd = open("map.ber", O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Can't open the file\n", 2);
        return (1);
    }
    map = create_map(fd);
    close(fd);
    if (!map)
    {
        ft_putstr_fd("Problem when creating the map\n", 2);
        return (1);
    }
    m.map = map;    
    m.mlx = mlx_init();
    if (!m.mlx)
        return (1);

    m.window = mlx_new_window(m.mlx,/* WIDTH_WINDOW, HEIGHT_WINDOW,*/ "My Game");
    if (!m.window)
    {
        mlx_destroy_display(m.mlx);
        return (free(m.mlx), 1);
    }
    
    load_player(&m, &m.sprites);
    load_map(&m, &m.sprites);
    load_utils(&m, &m.sprites);

    m.game.player_anim_frame = 0;
    m.game.player_dir = 0;
    m.game.enemy_anim_frame = 0;

    map_draw(map, &m, &m.sprites, &m.game);
    mlx_hook(m.window, 17, 0, close_window, &m);
    mlx_hook(m.window, KeyPress, KeyPressMask, key_info, &m);

    // mlx_string_put
    mlx_loop(m.mlx);
    destroy_sprites(&m, &m.sprites);
    close_free_all(m, map);
    return (0);
}

int key_info(int keycode, t_data *m)
{
    int x;
    int y;
    
    find_player_pos(m);
    x = m->game.player_x;
    y = m->game.player_y;
    if (keycode == 65307)
        close_window(m);
    else if (keycode == 97) //a
        player_left(m);   
    else if (keycode == 119) //w
        player_forward(m);
    else if (keycode == 115) //s
        player_back(m);
    else if (keycode == 100) //d
        player_right(m);
    
    if (m -> map[y][x] == '1')
        return (0);
    m -> map[y][x] = '0';
    m ->map[m->game.player_y][m->game.player_x] = 'P';
    m->game.player_anim_frame = (m -> game.player_anim_frame + 1) % 3;
    map_draw(m ->map, m, &m->sprites, &m->game);
    return (0);
}


int close_window(t_data *m)
{
    mlx_destroy_window(m->mlx, m->window);
    exit(EXIT_SUCCESS);
    return(0);
}

void    close_free_all(t_data m, char **map)
{
    mlx_destroy_window(m.mlx, m.window);
    mlx_destroy_display(m.mlx);
    free(m.mlx);
    free_tab(map);
}

void destroy_sprites(t_data *m, t_sprites *sprites)
{
    mlx_destroy_image(m->mlx, sprites->playerbottomleft);
    mlx_destroy_image(m->mlx, sprites->playerbottommid);
    mlx_destroy_image(m->mlx, sprites->playerbottomright);
    mlx_destroy_image(m->mlx, sprites->playerleftleft);
    mlx_destroy_image(m->mlx, sprites->playerleftmid);
    mlx_destroy_image(m->mlx, sprites->playerleftright);
    mlx_destroy_image(m->mlx, sprites->playerrightleft);
    mlx_destroy_image(m->mlx, sprites->playerrightmid);
    mlx_destroy_image(m->mlx, sprites->playerrightright);
    mlx_destroy_image(m->mlx, sprites->playertopright);
    mlx_destroy_image(m->mlx, sprites->playertopmid);
    mlx_destroy_image(m->mlx, sprites->playertopleft);
    mlx_destroy_image(m->mlx, sprites->wallbluebottom);
    mlx_destroy_image(m->mlx, sprites->wallblueleft);
    mlx_destroy_image(m->mlx, sprites->wallblueright);
    mlx_destroy_image(m->mlx, sprites->wallbluetop);
    mlx_destroy_image(m->mlx, sprites->wallwhitebottom);
    mlx_destroy_image(m->mlx, sprites->wallwhiteleft);
    mlx_destroy_image(m->mlx, sprites->wallwhiteright);
    mlx_destroy_image(m->mlx, sprites->wallwhitetop);
    mlx_destroy_image(m->mlx, sprites->floorblue);
    mlx_destroy_image(m->mlx, sprites->floorwhite);
    mlx_destroy_image(m->mlx, sprites->cheese);
    mlx_destroy_image(m->mlx, sprites->fakecheese);
    mlx_destroy_image(m->mlx, sprites->exit);
    mlx_destroy_image(m->mlx, sprites->enemy1);
    mlx_destroy_image(m->mlx, sprites->enemy2);
    mlx_destroy_image(m->mlx, sprites->enemy3);
    mlx_destroy_image(m->mlx, sprites->jerrydeath);
    mlx_destroy_image(m->mlx, sprites->trapopen);
    mlx_destroy_image(m->mlx, sprites->trapclose);
}