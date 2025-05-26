/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:24:46 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/26 10:26:48 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// char    **create_map(int file)
// {
//     char    **map;
//     char    *line;
//     int i;

//     i = 0;
//     map = malloc(sizeof(char *) * (nb_lines(file) + 1));
//     if (!map)
//         return (NULL);
//     while((line = get_next_line(file)) != NULL)
//         map[i++] = line;
//     map[i] = NULL;
//     return (map);
// }


char **create_map(int file)
{
    t_list  *lst = NULL, *last = NULL, *tmp;
    char    **map;
    char    *line;
    int     size = 0, i = 0;

    // Lecture du fichier et stockage dans une liste chaînée
    while ((line = get_next_line(file)) != NULL)
    {
        tmp = malloc(sizeof(t_list));
        if (!tmp)
        {
            free(line);
            ft_lstclear(&lst, NULL);
            return NULL;
        }
        tmp->line = line;
        tmp->next = NULL;
        if (!lst)
            lst = tmp;
        else
            last->next = tmp;
        last = tmp;
        size++;
    }
    // Allocation du tableau final
    map = malloc(sizeof(char *) * (size + 1));
    if (!map)
    {
        ft_lstclear(&lst, NULL);
        return NULL;
    }
    // Remplissage du tableau
    tmp = lst;
    while (tmp)
    {
        map[i++] = tmp->line;
        tmp = tmp->next;
    }
    map[i] = NULL;
    // Libération de la liste (mais pas des lignes, elles sont dans map)
    tmp = lst;
    while (tmp)
    {
        t_list *next = tmp->next;
        free(tmp);
        tmp = next;
    }
    return map;
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
            put_floor(mlx, sprites, x, y);
            if (map[y][x] == '1')
                put_wall(mlx, sprites, x, y);
            // else if (map[y][x] == '0')
            //    put_floor(mlx, sprites, x, y);
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
