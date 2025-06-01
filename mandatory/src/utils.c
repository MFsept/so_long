/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:02:41 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/01 20:15:23 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	update_map(t_data *m, int x, int y)
{
	if (m->game.player_x != x || m->game.player_y != y)
	{
		m->game.steps++;
		ft_printf("Steps: %d\n", m->game.steps);
	}
	if (m->map[m->game.player_y][m->game.player_x] == 'C')
		m->game.collected++;
	if (m->map[m->game.player_y][m->game.player_x] == 'E')
	{
		if (m->game.collected == m->game.total_collectibles)
			close_window(m);
		return (0);
	}
	m->map[y][x] = '0';
	m->map[m->game.player_y][m->game.player_x] = 'P';
	m->game.player_anim_frame = (m->game.player_anim_frame + 1) % 3;
	map_draw(m->map, m, &m->sprites, &m->game);
	return (0);
}

int	key_info(int keycode, t_data *m)
{
	int	x;
	int	y;

	find_player_pos(m);
	x = m->game.player_x;
	y = m->game.player_y;
	if (keycode == 65307)
		close_window(m);
	else if (keycode == 97) // a
		player_left(m);
	else if (keycode == 119) // w
		player_forward(m);
	else if (keycode == 115) // s
		player_back(m);
	else if (keycode == 100) // d
		player_right(m);
	else
		return (0);
	if (m->map[y][x] == '1')
		return (0);
	update_map(m, x, y);
	return (0);
}

int	close_window(t_data *m)
{
	mlx_destroy_window(m->mlx, m->window);
	exit(EXIT_SUCCESS);
	return (0);
}

void	close_free_all(t_data *m, char **map)
{
	mlx_destroy_window(m->mlx, m->window);
	mlx_destroy_display(m->mlx);
	free(m->mlx);
	free_tab(map);
}

void	destroy_sprites(t_data *m, t_sprites *sprites)
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
	// mlx_destroy_image(m->mlx, sprites->cheese);
	mlx_destroy_image(m->mlx, sprites->exit);
}
