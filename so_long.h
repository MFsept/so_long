/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:02:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/25 13:33:07 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>

# define HEIGHT_WINDOW 1500
# define WIDTH_WINDOW 939
# define TILE 32
# define HEIGHT_IMAGE 1500
# define WIDTH_IMAGE 939

# define X_MAX 11
# define Y_MAX 5

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*window;
}			t_data;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
}			t_map;

typedef struct s_sprites
{
	void	*wallbluebottom;
	void	*wallblueleft;
	void	*wallblueright;
	void	*wallbluetop;
	void	*wallwhitebottom;
	void	*wallwhiteleft;
	void	*wallwhiteright;
	void	*wallwhitetop;
	void	*floorblue;
	void	*floorwhite;
	void	*playerbottomleft;
	void	*playerbottommid;
	void	*playerbottomright;
	void	*playerleftleft;
	void	*playerleftmid;
	void	*playerleftright;
	void	*playerrightleft;
	void	*playerrightmid;
	void	*playerrightright;
	void	*playertopright;
	void	*playertopmid;
	void	*playertopleft;
	void	*cheese;
	void	*fakecheese;
	void	*exit;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*jerrydeath;
	void	*trapopen;
	void	*trapclose;
}			t_sprites;

typedef struct s_game
{
	int player_anim_frame; // 0, 1, 2
	int player_dir;        // 0 = bas, 1 = gauche, 2 = droite, 3 = haut
	int enemy_anim_frame;
    // ...autres champs...
}			t_game;

void		mlx_pixel(t_data *data, int x, int y, int color);
int			close_window(t_data *vars);
int			key_hook(int keycode, t_data *vars);

// map
char		**create_map(int file);
void		map_fill(char **map);
int			nb_lines(int file);
int			check_char(char **tab);
void	map_draw(char **map, t_data *mlx, t_sprites *sprites, t_game *game);

void		free_tab(char **tab);
void		close_free_all(t_data m, char **map);


//sprites 
void *load_sprite(void *mlx, char *path);
void load_player(t_data *m, t_sprites *sprites);
void load_map(t_data *m, t_sprites *sprites);
void load_utils(t_data *m, t_sprites *sprites);
void put_wall(t_data *mlx, t_sprites *sprites, int x, int y);
void put_floor(t_data *mlx, t_sprites *sprites, int x, int y);
void put_player(t_data *mlx, t_sprites *sprites, t_game *game, int x, int y);
void put_collectible(t_data *mlx, t_sprites *sprites, int x, int y);
void put_exit(t_data *mlx, t_sprites *sprites, int x, int y);
void put_ennemy(t_data *mlx, t_sprites *sprites, t_game *game, int x, int y);
void put_trapopen(t_data *mlx, t_sprites *sprites, int x, int y);
void put_trapclose(t_data *mlx, t_sprites *sprites, int x, int y);
#endif
