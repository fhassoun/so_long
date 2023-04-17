/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:25:01 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/17 13:21:31 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static mlx_image_t* image;

void ft_hook(void* param)
{
	sl_t *sl =  param;
	mlx_t* mlx = sl->mlx;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		sl->img.player ->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		sl->img.player ->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		sl->img.player ->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		sl->img.player ->instances[0].x += 5;
}

static void error(void)
{
	ft_printf("&s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	init_game(sl_t *sl)
{
	load_textures(sl);
	if (!(sl->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		error();
	if (!(sl->img.player = mlx_texture_to_image(sl->mlx, sl->textures.player)))
	{
		mlx_close_window(sl->mlx);
		error();
	}
	if (mlx_image_to_window(sl->mlx, sl->img.player , 0, 0) == -1)
	{
		mlx_close_window(sl->mlx);
		error();
	}
}

int main(int argc, char* argv[])
{
	sl_t sl;
	
	if(argc != 2)
	{
		ft_printf("%s\n", "Usage: ./so_long path/to/map");
		return (EXIT_SUCCESS);
	}
	sl.map_string = parse_map(argv[1]);
	init_game(&sl);
	

	mlx_loop_hook(sl.mlx, ft_hook, &sl);
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	return (EXIT_SUCCESS);
}

