/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:55:15 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/17 14:27:47 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(char *map, sl_t *sl)
{
	int		fd;
	char	*line;
	char	*map_string;

	fd = open(map, O_RDONLY);
	map_string = ft_calloc(1, 1);
	if (!map_string)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map_string = ft_strjoin(map_string, line);
			free(line);
		}
		else
			break ;
	}
	close (fd);
	sl->grid = ft_split(map_string, '\n');
}