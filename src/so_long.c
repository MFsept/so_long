/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:03:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/25 13:34:19 by mfernand         ###   ########.fr       */
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
    mlx_hook(m.window, 2, 1L<<0, key_hook, &m);   // Touche Escape
    mlx_hook(m.window, 17, 0, close_window, &m);  // Croix

    mlx_loop(m.mlx);

    close_free_all(m, map);
    return (0);
}





int key_hook(int keycode, t_data *vars)
{
    if (keycode == 65307)
        close_window(vars);
    return (0);
}
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
    // free(m.mlx);
    free_tab(map);
}

