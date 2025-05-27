/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:18:28 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/27 12:38:43 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void *load_sprite(void *mlx, char *path)
{
    int w, h;
    void *img = mlx_xpm_file_to_image(mlx, path, &w, &h);
    if (!img)
        ft_printf("Erreur chargement sprite : %s\n", path);
    return img;
}

void load_player(t_data *m, t_sprites *sprites)
{
    sprites->playerbottomleft = load_sprite(m->mlx, "assets/jerry_bottom/bottomleft3.xpm");
    sprites->playerbottommid = load_sprite(m->mlx, "assets/jerry_bottom/bottommid.xpm");
    sprites->playerbottomright = load_sprite(m->mlx, "assets/jerry_bottom/bottomright3.xpm");
    sprites->playerleftleft = load_sprite(m->mlx, "assets/jerry_left/leftleft3.xpm");
    sprites->playerleftmid = load_sprite(m->mlx, "assets/jerry_left/leftmid.xpm");
    sprites->playerleftright = load_sprite(m->mlx, "assets/jerry_left/leftright3.xpm");
    sprites->playerrightleft = load_sprite(m->mlx, "assets/jerry_right/rightleft3.xpm");
    sprites->playerrightmid = load_sprite(m->mlx, "assets/jerry_right/rightmid.xpm");
    sprites->playerrightright = load_sprite(m->mlx, "assets/jerry_right/rightright3.xpm");
    sprites->playertopright = load_sprite(m->mlx, "assets/jerry_top/topright3.xpm");
    sprites->playertopmid = load_sprite(m->mlx, "assets/jerry_top/topmid.xpm");
    sprites->playertopleft = load_sprite(m->mlx, "assets/jerry_top/topleft3.xpm");

}

void load_map(t_data *m, t_sprites *sprites)
{
    sprites->wallbluebottom = load_sprite(m->mlx, "assets/wall/wallbluebottom.xpm");
    sprites->wallblueleft = load_sprite(m->mlx, "assets/wall/wallblueleft.xpm");
    sprites->wallblueright = load_sprite(m->mlx, "assets/wall/wallblueright.xpm");
    sprites->wallbluetop = load_sprite(m->mlx, "assets/wall/wallbluetop.xpm");
    sprites->wallwhitebottom = load_sprite(m->mlx, "assets/wall/wallwhitebottom.xpm");
    sprites->wallwhiteleft = load_sprite(m->mlx, "assets/wall/wallwhiteleft.xpm");
    sprites->wallwhiteright = load_sprite(m->mlx, "assets/wall/wallwhiteright.xpm");
    sprites->wallwhitetop = load_sprite(m->mlx, "assets/wall/wallwhitetop.xpm");
    sprites->floorblue = load_sprite(m->mlx, "assets/floor/floorblue.xpm");
    sprites->floorwhite = load_sprite(m->mlx, "assets/floor/floorwhite.xpm");

}

void load_utils(t_data *m, t_sprites *sprites)
{
    sprites->cheese = load_sprite(m->mlx, "assets/cheese/cheese.xpm");
    sprites->fakecheese = load_sprite(m->mlx, "assets/cheese/fakecheese.xpm");
    sprites->exit = load_sprite(m->mlx, "assets/utils/doorleft.xpm");
    sprites->enemy1 = load_sprite(m->mlx, "assets/tom/tom.xpm");
    sprites->enemy2 = load_sprite(m->mlx, "assets/tom/tom1.xpm");
    sprites->enemy3 = load_sprite(m->mlx, "assets/tom/tom2.xpm");
    sprites->jerrydeath = load_sprite(m->mlx, "assets/utils/jerrydeath.xpm");
    sprites->trapopen = load_sprite(m->mlx, "assets/utils/trapopen.xpm");
    sprites->trapclose = load_sprite(m->mlx, "assets/utils/trapclose.xpm");
}

void put_wall(t_data *mlx, t_sprites *sprites, int x, int y)
{
    if (y == 0)
    {
        if ((x + y) % 2 == 1)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wallbluetop, x * TILE, y * TILE);
        else
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wallwhitetop, x * TILE, y * TILE);
    }
    else if(y == Y_MAX)
    {
        if ((x + y) % 2 == 1)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wallbluebottom, x * TILE, y * TILE);
        else
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wallwhitebottom, x * TILE, y * TILE);
    }
    else if (x == 0 && y != 0 && y != Y_MAX)
    {
        if ((x + y) % 2 == 1)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wallblueleft, x * TILE, y * TILE);
        else
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wallwhiteleft, x * TILE, y * TILE);
    }
    else if (x == X_MAX && y != 0 && y != Y_MAX)
    {
        if ((x + y) % 2 == 1)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wallblueright, x * TILE, y * TILE);
        else
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wallwhiteright, x * TILE, y * TILE);
    }
}

void put_floor(t_data *mlx, t_sprites *sprites, int x, int y)
{
    if ((x + y) % 2 == 0)
        mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->floorblue, x * TILE, y * TILE);
    else
        mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->floorwhite, x * TILE, y * TILE);
    // mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->floorblue, x * TILE, y * TILE);
}

void put_player(t_data *mlx, t_sprites *sprites, t_game *game, int x, int y)
{
    if (game->player_dir == 0) // bas
    {
        if (game->player_anim_frame == 0)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerbottommid, x * TILE, y * TILE);
        else if (game->player_anim_frame == 1)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerbottomleft, x * TILE, y * TILE);
        else
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerbottomright, x * TILE, y * TILE);
    }
    if (game->player_dir == 1) // left
    {
        if (game->player_anim_frame == 0)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerleftmid, x * TILE, y * TILE);
        else if (game->player_anim_frame == 1)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerleftleft, x * TILE, y * TILE);
        else
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerleftright, x * TILE, y * TILE);
    }
    if (game->player_dir == 2) // right
    {
        if (game->player_anim_frame == 0)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerrightmid, x * TILE, y * TILE);
        else if (game->player_anim_frame == 1)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerrightleft, x * TILE, y * TILE);
        else
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playerrightright, x * TILE, y * TILE);
    }
    else if (game->player_dir == 3) // top
    {
        if (game->player_anim_frame == 0)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playertopmid, x * TILE, y * TILE);
        else if (game->player_anim_frame == 1)
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playertopleft, x * TILE, y * TILE);
        else
            mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->playertopright, x * TILE, y * TILE);
    }
}

void put_collectible(t_data *mlx, t_sprites *sprites, int x, int y)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->cheese, x * TILE, y * TILE);
}

void put_exit(t_data *mlx, t_sprites *sprites, int x, int y)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->exit, x * TILE, y * TILE);
}

void put_ennemy(t_data *mlx, t_sprites *sprites, t_game *game, int x, int y)
{
    if (game -> enemy_anim_frame == 0)
        mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->enemy1, x * TILE, y * TILE);
    else if (game -> enemy_anim_frame == 1)
        mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->enemy2, x * TILE, y * TILE);
    else if (game -> enemy_anim_frame == 2)
        mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->enemy3, x * TILE, y * TILE);
}



void put_trapopen(t_data *mlx, t_sprites *sprites, int x, int y)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->fakecheese, x * TILE, y * TILE);
    mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->trapopen, x * TILE, y * TILE);
}

void put_trapclose(t_data *mlx, t_sprites *sprites, int x, int y)
{
    mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->trapclose, x * TILE, y * TILE);
}