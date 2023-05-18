/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:25:01 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/18 10:40:47 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_hook(mlx_key_data_t keydata, void *param)
{
	t_sl	*sl;
	mlx_t	*mlx;

	sl = param;
	mlx = sl->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(sl);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(sl);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(sl);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_right(sl);
}

void	init_game(t_sl *sl)
{
	sl->mlx = mlx_init(sl->map_width * IMG,
			sl->map_height * IMG, "Bzzzzzzzzzzzzzzzz!", true);
	if (!(sl->mlx))
		error();
	load_textures(sl);
	load_background(sl);
	create_map(sl);
}

void	cleanup(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->map_height)
	{
		free(sl->grid[i]);
		i++;
	}
	free(sl->grid);
	free(sl->map_string);
}

int	main(int argc, char *argv[])
{
	t_sl	sl;

	if (argc != 2)
	{
		ft_printf("%s\n", "Usage: ./so_long path/to/mapname.ber");
		return (EXIT_FAILURE);
	}
	check_extension(argv[1]);
	if (parse_map(argv[1], &sl) != 0
		|| check_map(&sl) != 0 || check_path(&sl) != 0)
	{
		exit(EXIT_FAILURE);
	}
	init_game(&sl);
	mlx_key_hook(sl.mlx, my_hook, &sl);
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	cleanup(&sl);
	return (EXIT_SUCCESS);
}
