/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:27:46 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/03 00:29:22 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	destroy_sprites(t_data *m, t_sprites *sprites)
{
	mlx_destroy_image(m->mlx, sprites->playerbottomleft);
	mlx_destroy_image(m->mlx, sprites->playerbottommid);
	mlx_destroy_image(m->mlx, sprites->playerbottomright);
	mlx_destroy_image(m->mlx, sprites->playerleftleft);
	mlx_destroy_image(m->mlx, sprites->playerleftmid);
	mlx_destroy_image(m->mlx, sprites->playerleftright);
	mlx_destroy_image(m->mlx, sprites->playerrightleft);
	mlx_destroy_image(m->mlx, sprites->playerrightmid);
	mlx_destroy_image(m->mlx, sprites->playerrightright);
	mlx_destroy_image(m->mlx, sprites->playertopright);
	mlx_destroy_image(m->mlx, sprites->playertopmid);
	mlx_destroy_image(m->mlx, sprites->playertopleft);
	mlx_destroy_image(m->mlx, sprites->wallbluebottom);
	mlx_destroy_image(m->mlx, sprites->wallblueleft);
	mlx_destroy_image(m->mlx, sprites->wallblueright);
	mlx_destroy_image(m->mlx, sprites->wallbluetop);
	mlx_destroy_image(m->mlx, sprites->wallwhitebottom);
	mlx_destroy_image(m->mlx, sprites->wallwhiteleft);
	mlx_destroy_image(m->mlx, sprites->wallwhiteright);
	mlx_destroy_image(m->mlx, sprites->wallwhitetop);
	mlx_destroy_image(m->mlx, sprites->floorblue);
	mlx_destroy_image(m->mlx, sprites->floorwhite);
	mlx_destroy_image(m->mlx, sprites->cheese);
	mlx_destroy_image(m->mlx, sprites->exit);
}
void    destroy_player(t_data *m, t_sprites *sprites)
{
    
}