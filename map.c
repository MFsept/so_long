/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:24:46 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/24 21:43:59 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **create_map(int file)
{
    char    **map;
    char    *line;
    int i;

    i = 0;
    map = malloc(sizeof(char *) * nb_lines(file) + 1);
    if (!map)
        return (NULL);
    while((line = get_next_line(file)) != NULL)
        map[i++] = line;
    map[i] = NULL;
    return (map);
}

void map_fill(char **map)
{
    int x;
    int y;

    y = 0;
    if (!check_char(map))
        return ;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            ft_putchar_fd(map[y][x], 1);
            x++;
        }
        ft_putchar_fd('\n', 1);
        y++;
    }
}

int nb_lines(int file)
{
    char    *line;
    int count;

    count = 0;
    while((line = get_next_line(file)) != NULL)
    {
        count++;
        free(line);
    }
    return (count);
}

int check_char(char **tab)
{
    int i;
    int j;

    j = 0;
    while(tab[j])
    {
        i = 0;
        while(tab[j][i])
        {
            if (tab[j][i] == '0')
                i++;
            else if (tab[j][i] == '1')
                i++;
            else if (tab[j][i] == 'P' || tab[j][i] == 'X')
                i++;
            else if (tab[j][i] == 'E')
                i++;
            else if (tab[j][i] == 'C')
                i++;
            else
                return (0);
        }
        j++;
    }
    return (1);
}
// void	map_draw(char **map, t_data *mlx, t_img *sprites)
// {
//     int	x;
//     int	y;

//     y = 0;
//     while (map[y])
//     {
//         x = 0;
//         while (map[y][x])
//         {
//             if (map[y][x] == '1')
//                 mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->wall, x * TILE, y * TILE);
//             else if (map[y][x] == '0')
//                 mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->floor, x * TILE, y * TILE);
//             else if (map[y][x] == 'P')
//                 mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->player, x * TILE, y * TILE);
//             else if (map[y][x] == 'C')
//                 mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->collectible, x * TILE, y * TILE);
//             else if (map[y][x] == 'E')
//                 mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->exit, x * TILE, y * TILE);
//             else if (map[y][x] == 'X')
//                 mlx_put_image_to_window(mlx->mlx, mlx->window, sprites->enemy, x * TILE, y * TILE);
//             x++;
//         }
//         y++;
//     }
// }
