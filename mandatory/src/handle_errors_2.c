/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:16:11 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/31 15:16:57 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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