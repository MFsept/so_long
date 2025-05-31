/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:39:56 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/31 14:22:27 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_errors(t_data *m, int ac, char **av)
{
	if (!check_file(ac, av))
		exit(EXIT_FAILURE);
	else if (!(check_map(m)))
		exit(EXIT_FAILURE);
	else if (!(check_content(m)))
		exit(EXIT_FAILURE);
	else if (!(check_double(m)))
		exit(EXIT_FAILURE);
	else if (!(check_wall(m)))
		exit(EXIT_FAILURE);
	// else if (!(check_valid_path(m)))
	//     exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
int	check_file(int ac, char **av)
{
	if (ac != 2)
	{
		perror("Wrong number of arguments");
		return (0);
	}
	if (!(ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) == 0))
	{
		perror("Bad extension for the map");
		return (0);
	}
	return (1);
}
int	check_map(t_data *m)
{
	size_t	len;
	int		i;

	i = 0;
	if (!m->map || !m->map[0])
		return (0);
	len = ft_strlen(m->map[0]);
	while (m->map[i])
	{
		if (ft_strlen(m->map[i]) != len && !m->map[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_content(t_data *m)
{
	static int	y = -1;
	int			x;
	static int	exit = 0;
	static int	coll = 0;
	static int	player = 0;

	while (m->map[++y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'P')
				player++;
			else if (m->map[y][x] == 'C')
				coll++;
			else if (m->map[y][x] == 'E')
				exit++;
			else if (m->map[y][x] != '0' && m->map[y][x] != '1')
				return (0);
			x++;
		}
	}
	if (player != 1 || exit < 1 || coll < 1)
		return (0);
	return (1);
}
int	check_double(t_data *m)
{
	int	i;
	int	j;
	int	count_exit;
	int	count_player;

	j = 0;
	count_exit = 0;
	count_player = 0;
	while (m->map[j])
	{
		i = 0;
		while (m->map[j][i])
		{
			if (m->map[j][i] == 'P')
				count_player++;
			else if (m->map[j][i] == 'E')
				count_exit++;
			i++;
		}
		j++;
	}
	if (count_exit != 1 || count_player != 1)
		return (0);
	return (1);
}
int	check_wall(t_data *m)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	j = 0;
	height = 0;
	if (!m->map || !m->map[0])
		return (0);
	width = ft_strlen(m->map[0]);
	while (m->map[height])
		height++;
	i = 0;
	while (i < width)
	{
		if (m->map[0][i] != '1' || m->map[height - 1][i] != '1')
			return (0);
		i++;
	}
	j = -1;
	while (++j < height)
		if (m->map[j][0] != '1' || m->map[j][width - 1] != '1')
			return (0);
	return (1);
}

// int check_valid_path(t_data m)
// {
// }