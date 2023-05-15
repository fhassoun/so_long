/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:06:39 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/15 14:15:09 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
int	check_newline(t_sl *sl)
{
	int	i;
	size_t	len;

	len = ft_strlen(sl->grid[0]);
	i = 1;
	while (i < sl->map_height)
	{
		if (len != ft_strlen(sl->grid[i]))
			return (1);
		i++;
	}
	return (0);
} */

int	check_map(t_sl *sl)
{
	return (check_border(sl) +
		// check_newline(sl) +
		check_content(sl) +
		check_limits(sl) +
		check_rect(sl));
	// int	a;
	// int	b;
	// int	c;
	// int	d;
	// int	e;

	// a = check_border(sl);
	// b = check_content(sl);
	// c = check_limits(sl);
	// d = check_extension(sl);
	// e = check_rect(sl);
	// if ((a + b + c + d + e == 0))
}