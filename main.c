/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:25:01 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/12 11:59:57 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static mlx_image_t* image;

void my_hook(mlx_key_data_t keydata,void* param)
{
	t_sl *sl =  param;
	mlx_t* mlx = sl->mlx;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
		// sl->img.player ->instances[0].y -= 5;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_up(sl);
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		// sl->img.player ->instances[0].y += 5;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_down(sl);
	// if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		// sl->img.player ->instances[0].x -= 5;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_left(sl);
	// if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		// sl->img.player ->instances[0].x += 5;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_right(sl);
}

void error_message(char *error_message)
{
	ft_printf("Error\n%s\n", error_message);
}

void error(void)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}


void	init_game(t_sl *sl)
{
	if (!(sl->mlx = mlx_init(sl->map_width * IMG, sl->map_height * IMG, "Bzzzzzzzzzzzzzzzz!", true)))
		error();
	load_textures(sl);
	

	load_background(sl);
	create_map(sl);
	/* if (mlx_image_to_window(sl->mlx, sl->img.player , 0, 0) == -1)
	{
		mlx_close_window(sl->mlx);
		error();
	} */
}

void cleanup(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->map_height )
	{
		free(sl->grid[i]);
		i++;
	}
	free(sl->grid);
}

int main(int argc, char* argv[])
{
	t_sl sl;
	
	if(argc != 2)
	{
		ft_printf("%s\n", "Usage: ./so_long path/to/mapname.ber");
		return (EXIT_SUCCESS);
	}
	check_extension(argv[1]);
	parse_map(argv[1], &sl);
	if (check_map(&sl) != 0 || check_path(&sl) != 0)
		exit(EXIT_FAILURE);

	
	init_game(&sl);
	// ft_printf("Game Start\nx: %i	y: %i\n\n\n", sl.ppos.x, sl.ppos.y);

	
	mlx_key_hook(sl.mlx, my_hook, &sl);
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	ft_printf("%s\n", "cleaning up!");
	cleanup(&sl);
	return (EXIT_SUCCESS);
}

