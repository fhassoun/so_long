/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:47:31 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/21 14:31:01 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(t_sl *sl)
{
	int	i;
	int	j;

	j = 0;
	while (j < sl->map_height)
	{
		i = 0;
		while (i < sl->map_width)
		{
			if ((sl->grid[0][i] != '1')
				|| (sl->grid[sl->map_height - 1][i] != '1')
				|| (sl->grid[j][0] != '1')
				|| (sl->grid[j][sl->map_width - 1] != '1'))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_limits(t_sl *sl)
{
	int	i;
	int	j;

	sl->limits.collectables = 0;
	sl->limits.player = 0;
	sl->limits.exits = 0;
	j = 0;
	while (j < sl->map_height)
	{
		i = 0;
		while (i < sl->map_width)
		{
			if (sl->grid[j][i] == 'E')
				sl->limits.exits++;
			if (sl->grid[j][i] == 'P')
				sl->limits.player++;
			if (sl->grid[j][i] == 'C')
				sl->limits.collectables++;
			i++;
		}
		j++;
	}
	if (sl->limits.player != 1 || sl->limits.exits != 1
		|| sl->limits.collectables < 1)
		return (1);
	return (0);
}
