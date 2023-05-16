/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:33:15 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/16 11:14:56 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	flood_fill(t_sl *tmp, int y, int x)
{
	if (tmp->grid[y][x] == '1')
		return (0);
	if (tmp->grid[y][x] == 'C')
		tmp->limits.collectables--;
	if (tmp->grid[y][x] == 'E')
	{
		tmp->limits.exits = 1;
		return (0);
	}
	tmp->grid[y][x] = '1';
	if (flood_fill(tmp, y + 1, x))
		return (1);
	if (flood_fill(tmp, y - 1, x))
		return (1);
	if (flood_fill(tmp, y, x + 1))
		return (1);
	if (flood_fill(tmp, y, x - 1))
		return (1);
	return (0);
}

int	check_path(t_sl *sl)
{
	t_sl	tmp;
	int		k;

	k = 0;
	tmp.map_height = sl->map_height;
	tmp.map_width = sl->map_width;
	tmp.grid = (char **)malloc(tmp.map_height * sizeof(char *));
	if (!tmp.grid)
		error_message("Memory allocation failed");
	tmp.limits.collectables = sl->limits.collectables;
	tmp.limits.exits = 0;
	while (k < tmp.map_height)
	{
		tmp.grid[k] = ft_strdup(sl->grid[k]);
		k++;
	}
	flood_fill(&tmp, sl->ppos.x, sl->ppos.y);
	if (!(tmp.limits.exits == 1 && tmp.limits.collectables == 0))
	{
		error_message("No valid path available");
		return (1);
	}
	free_grid(tmp.grid, tmp.map_height);
	return (0);
}
