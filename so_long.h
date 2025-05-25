/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:02:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/25 12:05:07 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "libft/libft.h"
#include "minilibx-linux/mlx_int.h"
#include "minilibx-linux/mlx.h"
#include <fcntl.h>

#define HEIGHT_WINDOW 1500
#define WIDTH_WINDOW 939
#define TILE 32
#define HEIGHT_IMAGE 1500
#define WIDTH_IMAGE 939

#define X_MAX 36
#define Y_MAX


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

typedef struct s_sprites
{
    void    *wallbluebottom;
    void    *wallblueleft;
    void    *wallblueright;
    void    *wallbluetop;
    void    *wallwhitebottom;
    void    *wallwhiteleft;
    void    *wallwhiteright;
    void    *wallwhitetop;
    void    *floorblue;
    void    *floorwhite;
    void    *playerbottomleft;
    void    *playerbottommid;
    void    *playerbottomright;
    void    *playerleftleft;
    void    *playerleftmid;
    void    *playerleftright;
    void    *playerrightleft;
    void    *playerrightmid;
    void    *playerrightright;
    void    *playertopright;
    void    *playertopmid;
    void    *playertopleft;
    void    *collectible;
    void    *exit;
    void    *enemy;
    void    *trap;
}   t_sprites;


void    mlx_pixel(t_data *data, int x, int y, int color);
int close_window(t_data *vars);
int key_hook(int keycode, t_data *vars);




// map
char    **create_map(int file);
void map_fill(char **map);
int nb_lines(int file);
int check_char(char **tab);


void	free_tab(char **tab);
void    close_free_all(t_data m, char **map);
#endif
