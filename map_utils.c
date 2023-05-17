/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:06:39 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/17 11:54:11 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_sl *sl)
{
	sl->limits.collectables = 0;
	sl->limits.player = 0;
	sl->limits.exits = 0;
	return (check_border(sl)
		+ check_content(sl)
		+ check_limits(sl)
		+ check_rect(sl));
}

void	too_many_lines(t_sl *sl)
{
	int	i;
	int	j;

	j = -1;
	while (++j < sl->map_height)
	{
		i = -1;
		while (++i < sl->map_width)
		{
			if (sl->grid[j][i] == 'E')
				sl->limits.exits++;
			if (sl->grid[j][i] == 'P')
			{
				sl->limits.player++;
				sl->ppos.x = i;
				sl->ppos.y = j;
			}
			if (sl->grid[j][i] == 'C')
				sl->limits.collectables++;
		}
	}
}
