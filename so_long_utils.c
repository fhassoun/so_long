/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:26:01 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/15 12:37:45 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_sl *sl)
{
	mlx_close_window(sl->mlx);
	ft_printf("You collected all flowers and returned home. Good Job :)\n");
}

void	load_textures(t_sl *sl)
{
	load_empty(sl);
	load_wall(sl);
	load_collectible(sl);
	load_exit(sl);
	load_player(sl);
}

void	error_message(char *error_message)
{
	ft_printf("Error\n%s\n", error_message);
}

void	error(void)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}