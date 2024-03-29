/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:44:29 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/16 10:49:46 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* 
void load_empty(t_sl *sl)
{
	sl->textures.empty = mlx_load_png("./pics/grass.png");
	if (!sl->textures.empty)
		error_message("Problem with loading png");
	sl->img.empty = mlx_texture_to_image(sl->mlx, sl->textures.empty);
	if (!sl->img.empty)
		error_message("Problem with texture to image");
	mlx_delete_texture (sl->textures.empty);
} */

void	load_empty(t_sl *sl)
{
	xpm_t	*test;

	test = mlx_load_xpm42("./pics/grass.xpm42");
	if (!test)
		error_message("Problem with loading xpm1");
	sl->img.empty = mlx_texture_to_image(sl->mlx, &test->texture);
	if (!sl->img.empty)
		error_message("Problem with texture to image");
	mlx_delete_xpm42(test);
}

/* void load_wall(t_sl *sl)
{
	sl->textures.wall = mlx_load_png("./pics/tree.png");
	if (!sl->textures.wall)
		error_message("Problem with loading png");
	sl->img.wall = mlx_texture_to_image(sl->mlx, sl->textures.wall);
	if (!sl->img.wall)
		error_message("Problem with texture to image");
	mlx_delete_texture (sl->textures.wall);
} */

void	load_wall(t_sl *sl)
{
	xpm_t	*test;

	test = mlx_load_xpm42("./pics/tree.xpm42");
	if (!test)
		error_message("Problem with loading xpm2");
	sl->img.wall = mlx_texture_to_image(sl->mlx, &test->texture);
	if (!sl->img.wall)
		error_message("Problem with texture to image");
	mlx_delete_xpm42(test);
}

/* void load_collectible(t_sl *sl)
{
	sl->textures.collectible = mlx_load_png("./pics/flower.png");
	if (!sl->textures.collectible)
		error_message("Problem with loading png");
	sl->img.collectible = mlx_texture_to_image(sl->mlx, sl->textures.collectible);
	if (!sl->img.collectible)
		error_message("Problem with texture to image");
	mlx_delete_texture (sl->textures.collectible);
} */

void	load_collectible(t_sl *sl)
{
	xpm_t	*test;

	test = mlx_load_xpm42("./pics/flower.xpm42");
	if (!test)
		error_message("Problem with loading xpm3");
	sl->img.collectible = mlx_texture_to_image(sl->mlx, &test->texture);
	if (!sl->img.collectible)
		error_message("Problem with texture to image");
	mlx_delete_xpm42(test);
}

/* void load_exit(t_sl *sl)
{
	sl->textures.exit = mlx_load_png("./pics/beehive.png");
	if (!sl->textures.exit)
		error_message("Problem with loading png");
	sl->img.exit = mlx_texture_to_image(sl->mlx, sl->textures.exit);
	if (!sl->img.exit)
		error_message("Problem with texture to image");
	mlx_delete_texture (sl->textures.exit);
} */

void	load_exit(t_sl *sl)
{
	xpm_t	*test;

	test = mlx_load_xpm42("./pics/beehive.xpm42");
	if (!test)
		error_message("Problem with loading xpm4");
	sl->img.exit = mlx_texture_to_image(sl->mlx, &test->texture);
	if (!sl->img.exit)
		error_message("Problem with texture to image");
	mlx_delete_xpm42(test);
}

/* void load_player(t_sl *sl)
{
	sl->textures.player = mlx_load_png("./pics/bee.png");
	if (!sl->textures.player)
		error_message("Problem with loading png");
	sl->img.player = mlx_texture_to_image(sl->mlx, sl->textures.player);
	if (!sl->img.player)
		error_message("Problem with texture to image");
	mlx_delete_texture (sl->textures.player);
} */

void	load_player(t_sl *sl)
{
	xpm_t	*test;

	test = mlx_load_xpm42("./pics/bee.xpm42");
	if (!test)
		error_message("Problem with loading xpm5");
	sl->img.player = mlx_texture_to_image(sl->mlx, &test->texture);
	if (!sl->img.player)
		error_message("Problem with texture to image");
	mlx_delete_xpm42(test);
}
