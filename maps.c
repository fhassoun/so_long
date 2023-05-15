/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:55:15 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/15 15:06:34 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_dimensions(t_sl *sl)
{
	int	i;

	i = 0;
	sl->map_width = ft_strlen(sl->grid[0]);
	sl->map_height = 0;
	while (sl->grid[i])
	{
		sl->map_height++;
		i++;	
	}
	// ft_printf("width: %i\nheight: %i\n", sl->map_width,sl->map_height);
}

int	check_newline(char *map_string)
{
	int i;
	
	i = 0;
	while ( map_string[i] != '\0')
	{
		if (map_string[i] == '\n' && map_string[i + 1] == '\n')
		{
			
			error_message("Not a valid Map!");
			free(map_string);
			//exit (1);
			return (1);
		} 
		i++;
	}
	return (0);
}

int	parse_map(char *map, t_sl *sl)
{
	int		fd;
	char	*line;
	char	*map_string;

	fd = open(map, O_RDONLY);
	map_string = ft_calloc(1, 1);
	if (!map_string)
		return (1);
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
	if (check_newline(map_string) != 0)
		return (1);
	ft_printf("hallo?");
	sl->grid = ft_split(map_string, '\n');
	get_dimensions(sl);
	free(map_string);
	return (0);
}
