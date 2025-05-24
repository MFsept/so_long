/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:03:12 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/24 19:14:35 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    int     fd;
    char    **map;
    t_data  m;
    t_data  img;

    fd = open("map.ber", O_RDONLY);
    if (fd < 0)
    {
        ft_putstr_fd("Can't open the file\n", 2);
        return (1);
    }
    map = create_map(fd);
    if (!map)
    {
        ft_putstr_fd("Problem when creating the map\n",2);
        return (1);
    }
    close(fd);
    m.mlx = mlx_init();
    if (!m.mlx)
        return (1);
    
    m.window = mlx_new_window(m.mlx, HEIGHT_WINDOW, WIDTH_WINDOW, "My Game");
    if (!m.window)
    {
        mlx_destroy_display(m.mlx);
        return (free(m.mlx), 1);
    }
    img.img = mlx_new_image(m.mlx, HEIGHT_IMAGE, WIDTH_IMAGE);
    if (!img.img)
    {
        mlx_destroy_display(m.mlx);
        return (free(m.mlx), 1);
    }
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    
    mlx_pixel(&img, HEIGHT_IMAGE / 2, WIDTH_IMAGE / 2, 0xff0000);
    map_fill(map);
    mlx_put_image_to_window(m.mlx, m.window, img.img, 0, 0);
    

    mlx_hook(m.window, 2, 1L<<0, close_window, &m);
    mlx_hook(m.window, 4, 1L<<2, close_window, &m);

    mlx_loop(m.mlx);
    mlx_destroy_window(m.mlx, m.window);
    mlx_destroy_display(m.mlx);
    free(m.mlx);
    free_tab(map);
    return (0);
}

void    mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close_window(int keycode, t_data *vars)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->window);
        exit(EXIT_SUCCESS);
    }
    else if (keycode == 1)
    {
        mlx_destroy_window(vars->mlx, vars->window);
        exit(EXIT_SUCCESS);
    }
    return(0);
}