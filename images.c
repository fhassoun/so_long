/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:44:29 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/28 13:07:10 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_sl *sl)
{
	sl->textures.empty = mlx_load_png("./pics/grass.png");
	if (!(sl->img.empty = mlx_texture_to_image(sl->mlx, sl->textures.empty)))
	{
		mlx_close_window(sl->mlx);
		error();
	}
	
	sl->textures.wall = mlx_load_png("./pics/tree.png");
	if (!(sl->img.wall = mlx_texture_to_image(sl->mlx, sl->textures.wall)))
	{
		mlx_close_window(sl->mlx);
		error();
	}
	
	sl->textures.collectible = mlx_load_png("./pics/flower.png");
	if (!(sl->img.collectible = mlx_texture_to_image(sl->mlx, sl->textures.collectible)))
	{
		mlx_close_window(sl->mlx);
		error();
	}

	
	sl->textures.exit = mlx_load_png("./pics/beehive.png");
	if (!(sl->img.exit = mlx_texture_to_image(sl->mlx, sl->textures.exit)))
	{
		mlx_close_window(sl->mlx);
		error();
	}
	
	sl->textures.player = mlx_load_png("./pics/bee.png");
	if (!(sl->img.player = mlx_texture_to_image(sl->mlx, sl->textures.player)))
	{
		mlx_close_window(sl->mlx);
		error();
	}
}


/* void load_grass_texture(t_sl *sl)
{
	// mlx_texture_t	*grass;

	sl->textures.wall = mlx_load_png("./pics/grass.png");
	if (!sl->textures.wall)
		error_message("Problem with loading png");
	sl->img.wall = mlx_texture_to_image(sl->mlx, sl->textures.wall);
	if (!sl->img.wall)
		error_message("Problem with texture to image");
	mlx_delete_texture (sl->textures.wall);
} */

void	fill_background(t_sl *sl)
{
	int		x;
	int		y;

	y = 0;
	while (y < sl->map_height)
	{
		x = 0;
		while (x < sl->map_width)
		{
			if (mlx_image_to_window(sl->mlx, sl->img.empty,
					x * IMG, y * IMG) < 0)
				error_message("Failed to put image to window");
			x++;
		}
		y++;
	}
}

