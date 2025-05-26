/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:03:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/26 12:06:22 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(void)
{
    int     fd;
    char    **map;
    t_data  m;
    t_sprites sprites;
    t_game  game;

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

    m.window = mlx_new_window(m.mlx, WIDTH_WINDOW, HEIGHT_WINDOW, "My Game");
    if (!m.window)
    {
        mlx_destroy_display(m.mlx);
        return (free(m.mlx), 1);
    }
    // Chargement des sprites
    load_player(&m, &sprites);
    load_map(&m, &sprites);
    load_utils(&m, &sprites);

    game.player_anim_frame = 0;
    game.player_dir = 0;
    game.enemy_anim_frame = 0;

    map_draw(map, &m, &sprites, &game);
    mlx_hook(m.window, 17, 0, close_window, &m);
    mlx_hook(m.window, KeyPress, KeyPressMask, key_info, &m); //KeyPress //KeyMasks

    // mlx_string_put
    mlx_loop(m.mlx);
    destroy_sprites(&m, &sprites);
    close_free_all(m, map);
    return (0);
}

int key_info(int keycode, t_data *m)
{
    find_player_pos(m);
    if (keycode == 65307)
        close_window(m);
    else if (keycode == 97) //a
        player_forward(&m -> game);   
    else if (keycode == 119) //w
    player_forward(&m -> game);
    else if (keycode == 115) //s
        player_back(&m -> game);
    else if (keycode == 100) //d
        player_right(&m -> game);
    
//     if (//aucun changement)
//         return (0);
//     map[y][x] = '0'; // a trouver comment faire
//     map[m->game.player_y][m->game.player_x] = 'P';
//     m->game.player_anim_frame = (m -> game.player_anim_frame + 1) % 3;
//     map_draw(m ->map, m, &m->sprites, &m->game);
//     return (0);
// }

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
