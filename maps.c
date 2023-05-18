/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:55:15 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/18 10:34:48 by fhassoun         ###   ########.fr       */
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
}

int	check_newline(char *map_string)
{
	int	i;

	i = 0;
	while (map_string[i] != '\0')
	{
		if (map_string[i] == '\n' && map_string[i + 1] == '\n')
		{
			error_message("Not a valid Map!");
			return (1);
		}
		i++;
	}
	return (0);
}

void	too_long_again(t_sl *sl, char *line, int fd)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			sl->map_string = ft_gnl_strjoin(sl->map_string, line);
			free(line);
		}
		else
			break ;
	}
}

int	parse_map(char *map, t_sl *sl)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		error_message("Could not open Map!");
		return (1);
	}
	sl->map_string = ft_calloc(1, 1);
	if (!sl->map_string)
		return (1);
	line = ft_calloc(1, 1);
	too_long_again(sl, line, fd);
	close (fd);
	if (check_newline(sl->map_string) != 0)
	{
		free(line);
		free(sl->map_string);
		return (1);
	}
	sl->grid = ft_split(sl->map_string, '\n');
	free(line);
	get_dimensions(sl);
	return (0);
}
