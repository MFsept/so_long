/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:03:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/28 15:36:10 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	int fd;
	t_data m;

	if (check_file(ac, av) == 0)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Can't open the file\n", 2);
		return (1);
	}
	m.map = create_map(fd);
	close(fd);
	if (!m.map)
	{
		ft_putstr_fd("Problem when creating the map\n", 2);
		return (1);
	}
	m.mlx = mlx_init();
	if (!m.mlx)
		return (1);
	m.window = mlx_new_window(m.mlx, width_window(m), height_window(m), "My Game");
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
	m.game.steps = 0;

	m.game.total_collectibles = count_collect(&m);
	m.game.collected = 0;
	map_draw(m.map, &m, &m.sprites, &m.game);
	mlx_hook(m.window, 17, 0, close_window, &m);
	mlx_hook(m.window, KeyPress, KeyPressMask, key_info, &m);

	// mlx_string_put
	mlx_loop(m.mlx);
	destroy_sprites(&m, &m.sprites);
	close_free_all(m, m.map);
	return (0);
}
static void setup_display(t_data m, int fd)
{
    m.map = create_map(fd);
	close(fd);
	if (!m.map)
	{
		ft_putstr_fd("Problem when creating the map\n", 2);
		return (1);
	}
	m.mlx = mlx_init();
	if (!m.mlx)
		return (1);
	m.window = mlx_new_window(m.mlx, width_window(m), height_window(m), "My Game");
	if (!m.window)
	{
		mlx_destroy_display(m.mlx);
		return (free(m.mlx), 1);
	}
}