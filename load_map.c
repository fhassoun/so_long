/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:19 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/17 14:24:06 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_background(t_sl *sl)
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

void	image_select(t_sl *sl, int y, int x)
{
	if (sl->grid[y][x] == 'P')
	{
		mlx_image_to_window(sl->mlx, sl->img.player, x * IMG, y * IMG);
		sl->ppos.x = x;
		sl->ppos.y = y;
	}
	if (sl->grid[y][x] == 'C')
		mlx_image_to_window(sl->mlx, sl->img.collectible, x * IMG, y * IMG);
	if (sl->grid[y][x] == 'E')
		mlx_image_to_window(sl->mlx, sl->img.exit, x * IMG, y * IMG);
	if (sl->grid[y][x] == '1')
		mlx_image_to_window(sl->mlx, sl->img.wall, x * IMG, y * IMG);
}

void	create_map(t_sl *sl)
{
	int		x;
	int		y;

	y = 0;
	sl->moves = 0;
	sl->limits.collected = 0;
	while (y < sl->map_height)
	{
		x = 0;
		while (x < sl->map_width)
		{
			image_select(sl, y, x);
			x++;
		}
		y++;
	}
}
