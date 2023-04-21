/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:44:29 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/21 12:50:51 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_sl *sl)
{
	sl->textures.empty = mlx_load_png("./pics/grass.png");
	sl->textures.wall = mlx_load_png("./pics/tree_small.png");
	sl->textures.collectible = mlx_load_png("./pics/flower.png");
	sl->textures.exit = mlx_load_png("./pics/beehive_small.png");
	sl->textures.player = mlx_load_png("./pics/bee3.png");
}