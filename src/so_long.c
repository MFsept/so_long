/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:03:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/25 21:43:48 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

    // Initialisation de l'animation (exemple)
    game.player_anim_frame = 0;
    game.player_dir = 0;
    game.enemy_anim_frame = 0;

    // Affichage de la map
    map_draw(map, &m, &sprites, &game);

    // Hooks pour fermer la fenêtre
    mlx_hook(m.window, 2, 1L<<0, key_hook, &m);
    mlx_hook(m.window, 17, 0, close_window, &m);

    // mlx_string_put
    mlx_loop(m.mlx);
    destroy_sprites(&m, &sprites);
    close_free_all(m, map);
    return (0);
}





int key_hook(int keycode, t_data *vars)
{
    if (keycode == 65307)
        close_window(vars);
    return (0);
}

// int key_hook(int keycode, t_data *vars)
// {
//     char **map = vars->map;
//     int x = 0, y = 0;
//     int found = 0;

//     // Trouve la position du joueur (P) avec des while
//     y = 0;
//     while (map[y] && !found)
//     {
//         x = 0;
//         while (map[y][x])
//         {
//             if (map[y][x] == 'P')
//             {
//                 found = 1;
//                 break;
//             }
//             x++;
//         }
//         if (!found)
//             y++;
//     }
//     if (!found)
//         return (0);

//     int nx = x, ny = y;
//     if (keycode == 65307) // echap
//         close_window(vars);
//     else if (keycode == 119) // w
//         ny--;
//     else if (keycode == 115) // s
//         ny++;
//     else if (keycode == 97) // a
//         nx--;
//     else if (keycode == 100) // d
//         nx++;
//     else
//         return (0); // Ignore les autres touches

//     // Vérifie que la case cible est dans la map
//     if (ny < 0 || nx < 0 || !map[ny] || !map[ny][nx])
//         return (0);

//     // Vérifie que la case cible n'est pas un mur
//     if (map[ny][nx] != '1')
//     {
//         map[y][x] = '0';
//         map[ny][nx] = 'P';
//         map_draw(map, vars, &vars->sprites, &vars->game);
//     }
//     return (0);
// }
int close_window(t_data *vars)
{
    mlx_destroy_window(vars->mlx, vars->window);
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