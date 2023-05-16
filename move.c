/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:25:42 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/16 13:28:09 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_collectible(t_sl *sl, int y, int x)
{
	int	i;

	i = 0;
	x = x * IMG;
	y = y * IMG;
	while (i < sl->limits.collectables)
	{
		if (sl->img.collectible->instances[i].x == x
			&& sl->img.collectible->instances[i].y == y)
		{
			sl->img.collectible->instances[i].enabled = false;
		}
		i++;
	}
}

void	move_up(t_sl *sl)
{
	if (sl->grid[sl->ppos.y - 1][sl->ppos.x] != '1')
	{
		if (sl->grid[sl->ppos.y - 1][sl->ppos.x] == 'C')
		{
			delete_collectible(sl, sl->ppos.y - 1, sl->ppos.x);
			sl->grid[sl->ppos.y - 1][sl->ppos.x] = '0';
			sl->limits.collected++;
		}
		if (sl->grid[sl->ppos.y - 1][sl->ppos.x] == 'E' &&
			sl->limits.collected == sl->limits.collectables)
		{
			game_over(sl);
			return ;
		}
		sl->ppos.y--;
		sl->img.player ->instances[0].y -= 1 * IMG;
		sl->moves++;
		ft_printf("Your Bee made %i moves...\n", sl->moves);
	}
}

void	move_down(t_sl *sl)
{
	if (sl->grid[sl->ppos.y + 1][sl->ppos.x] != '1')
	{
		if (sl->grid[sl->ppos.y + 1][sl->ppos.x] == 'C')
		{
			delete_collectible(sl, sl->ppos.y + 1, sl->ppos.x);
			sl->grid[sl->ppos.y + 1][sl->ppos.x] = '0';
			sl->limits.collected++;
		}
		if (sl->grid[sl->ppos.y + 1][sl->ppos.x] == 'E' &&
			sl->limits.collected == sl->limits.collectables)
		{
			game_over(sl);
			return ;
		}
		sl->ppos.y++;
		sl->img.player->instances[0].y += 1 * IMG;
		sl->moves++;
		ft_printf("Your Bee made %i moves...\n", sl->moves);
	}
}

void	move_right(t_sl *sl)
{
	if (sl->grid[sl->ppos.y][sl->ppos.x + 1] != '1')
	{
		if (sl->grid[sl->ppos.y][sl->ppos.x + 1] == 'C')
		{
			delete_collectible(sl, sl->ppos.y, sl->ppos.x + 1);
			sl->grid[sl->ppos.y][sl->ppos.x + 1] = '0';
			sl->limits.collected++;
		}
		if (sl->grid[sl->ppos.y][sl->ppos.x + 1] == 'E' &&
			sl->limits.collected == sl->limits.collectables)
		{
			game_over(sl);
			return ;
		}
		sl->ppos.x++;
		sl->img.player->instances[0].x += 1 * IMG;
		sl->moves++;
		ft_printf("Your Bee made %i moves...\n", sl->moves);
	}
}

void	move_left(t_sl *sl)
{
	if (sl->grid[sl->ppos.y][sl->ppos.x - 1] != '1')
	{
		if (sl->grid[sl->ppos.y][sl->ppos.x - 1] == 'C')
		{
			delete_collectible(sl, sl->ppos.y, sl->ppos.x - 1);
			sl->grid[sl->ppos.y][sl->ppos.x - 1] = '0';
			sl->limits.collected++;
		}
		if (sl->grid[sl->ppos.y][sl->ppos.x - 1] == 'E' &&
			sl->limits.collected == sl->limits.collectables)
		{
			game_over(sl);
			return ;
		}
		sl->ppos.x--;
		sl->img.player ->instances[0].x -= 1 * IMG;
		sl->moves++;
		ft_printf("Your Bee made %i moves...\n", sl->moves);
	}
}
