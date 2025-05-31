/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:31:59 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/31 14:12:37 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_bottom(t_data *mlx, t_game *game, int x, int y)
{
	if (game->player_anim_frame == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerbottomleft, x * TILE, y * TILE);
	else if (game->player_anim_frame == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerbottommid, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerbottomright, x * TILE, y * TILE);
}

static void	put_left(t_data *mlx, t_game *game, int x, int y)
{
	if (game->player_anim_frame == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerleftleft, x * TILE, y * TILE);
	else if (game->player_anim_frame == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerleftmid, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerleftright, x * TILE, y * TILE);
}

static void	put_right(t_data *mlx, t_game *game, int x, int y)
{
	if (game->player_anim_frame == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerrightleft, x * TILE, y * TILE);
	else if (game->player_anim_frame == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerrightmid, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playerrightright, x * TILE, y * TILE);
}

static void	put_top(t_data *mlx, t_game *game, int x, int y)
{
	if (game->player_anim_frame == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playertopleft, x * TILE, y * TILE);
	else if (game->player_anim_frame == 1)
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playertopmid, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window,
			mlx->sprites.playertopright, x * TILE, y * TILE);
}

void	put_player(t_data *mlx, t_game *game, int x, int y)
{
	if (game->player_dir == 0)
		put_bottom(mlx, game, x, y);
	else if (game->player_dir == 1)
		put_left(mlx, game, x, y);
	else if (game->player_dir == 2)
		put_right(mlx, game, x, y);
	else if (game->player_dir == 3)
		put_top(mlx, game, x, y);
}
