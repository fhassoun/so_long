/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:44:29 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/14 10:58:41 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(sl_t *sl)
{
	sl->textures.empty = mlx_load_png("./pics/bl-small.png");
	sl->textures.wall = mlx_load_png("./pics/bl-small.png");
	sl->textures.collectible = mlx_load_png("./pics/bl-small.png");
	sl->textures.exit = mlx_load_png("./pics/bl-small.png");
	sl->textures.player = mlx_load_png("./pics/bee2.png");
}