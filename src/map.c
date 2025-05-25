/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:24:46 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/25 13:33:24 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char    **create_map(int file)
{
    char    **map;
    char    *line;
    int i;

    i = 0;
    map = malloc(sizeof(char *) * (nb_lines(file) + 1));
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
void	map_draw(char **map, t_data *mlx, t_sprites *sprites, t_game *game)
{
    int	x;
    int	y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
                put_wall(mlx, sprites, x, y);
            else if (map[y][x] == '0')
                put_floor(mlx, sprites, x, y);
            else if (map[y][x] == 'P')
                put_player(mlx, sprites,game, x, y);
            else if (map[y][x] == 'C')
                put_collectible(mlx, sprites, x, y);
            else if (map[y][x] == 'E')
                put_exit(mlx, sprites, x, y);
            else if (map[y][x] == 'X')
                put_ennemy(mlx, sprites, game, x, y);
            else if (map[y][x] == 'T')
                put_trapopen(mlx, sprites, x, y);
            else if (map[y][x] == 't')
                put_trapclose(mlx, sprites, x, y);
            x++;
        }
        y++;
    }
}
