/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:02:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/24 22:45:57 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"
#include "minilibx-linux/mlx_int.h"
#include "minilibx-linux/mlx.h"
#include <fcntl.h>

#define HEIGHT_WINDOW 1920
#define WIDTH_WINDOW 1199

#define HEIGHT_IMAGE 1920
#define WIDTH_IMAGE 1199

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*window;
}				t_data;

typedef struct s_map
{
    char    **grid;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     moves;
}   t_map;

void    mlx_pixel(t_data *data, int x, int y, int color);
int close_window(int keycode, t_data *vars);



// map
char    **create_map(int file);
void map_fill(char **map);
int nb_lines(int file);
int check_char(char **tab);


void	free_tab(char **tab);
#endif