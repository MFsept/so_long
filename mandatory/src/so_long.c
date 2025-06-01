/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:03:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/01 18:09:37 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	game_init(t_data *m)
{
	m->game.player_anim_frame = 0;
	m->game.player_dir = 0;
	m->game.enemy_anim_frame = 0;
	m->game.steps = 0;
	m->game.total_collectibles = count_collect(m);
	m->game.collected = 0;
}

static int	setup_display(t_data *m, int fd)
{
	m->map = create_map(fd);
	close(fd);
	if (!m->map || !check_map(m))
	{
		ft_putstr_fd("Problem when creating the map\n", 2);
		return (1);
	}
	m->mlx = mlx_init();
	if (!m->mlx)
		return (1);
	m->window = mlx_new_window(m->mlx, width_window(m) * TILE, height_window(m)
			* TILE, "My Game");
	if (!m->window)
	{
		mlx_destroy_display(m->mlx);
		return (free(m->mlx), 1);
	}
	load_player(m, &m->sprites);
	load_map(m, &m->sprites);
	load_utils(m, &m->sprites);
	game_init(m);
	map_draw(m->map, m, &m->sprites, &m->game);
	mlx_hook(m->window, 17, 0, close_window, m);
	mlx_hook(m->window, KeyPress, KeyPressMask, key_info, m);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	m;

	if (!check_file(ac, av))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Can't open the file\n", 2);
		return (1);
	}
	if (setup_display(&m, fd))
		return (1);
	if (!check_errors(&m, ac, av))
		return (0);
	mlx_loop(m.mlx);
	destroy_sprites(&m, &m.sprites);
	close_free_all(m, m.map);
	return (0);
}
