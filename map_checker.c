/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:47:31 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/23 09:25:03 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(t_sl *sl)
{
	int	i;
	int	j;

	j = -1;
	while (++j < sl->map_height)
	{
		i = -1;
		while (++i < sl->map_width)
		{
			if ((sl->grid[0][i] != '1')
				|| (sl->grid[sl->map_height - 1][i] != '1')
				|| (sl->grid[j][0] != '1')
				|| (sl->grid[j][sl->map_width - 1] != '1'))
			{
						error_message("Invalid Map. Not surrounded by borders!");
				return (1);
			}
		}
	}
	return (0);
}

int	check_content(t_sl *sl)
{
	int	i;
	int	j;

	j = -1;
	while (++j < sl->map_height)
	{
		i = -1;
		while (++i < sl->map_width)
		{
			if (!(ft_strchr("PEC01\n", sl->grid[j][i])))
			{
				error_message("Map contains invalid characters");
				return (1);
			}
		}
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
	j = -1;
	while (++j < sl->map_height)
	{
		i = -1;
		while (++i < sl->map_width)
		{
			if (sl->grid[j][i] == 'E')
				sl->limits.exits++;
			if (sl->grid[j][i] == 'P')
				sl->limits.player++;
			if (sl->grid[j][i] == 'C')
				sl->limits.collectables++;
		}
	}
	if (sl->limits.player != 1 || sl->limits.exits != 1
		|| sl->limits.collectables < 1)
	{
		error_message("Map can only contain 1 Player, only 1 Exit and at least 1 Collectable!");
		return (1);
	}
	return (0);
}

int	check_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4))
	{
		error_message("Map is not a .ber file");
		exit (1);
	}
	return (0);
}

int	check_rect(t_sl *sl)
{
	int	i;
	size_t	len;

	i = 0;
	len = ft_strlen(sl->grid[i]);
	while (sl->grid[i])
	{
		if (ft_strlen(sl->grid[i]) != len)
		{
			error_message("Map is not rectangular");
			return (1);
		}
		i++;
	}
	return (0);
}

