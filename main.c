/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:25:01 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/13 13:46:56 by fhassoun         ###   ########.fr       */
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
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int main(int argc, const char* argv[])
{
	sl_t sl;
	
	//mlx_t* mlx;

	if (!(sl.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		error();
	mlx_texture_t* texture = mlx_load_png("./pics/bl-small.png");
	if (!(sl.img.player = mlx_texture_to_image(sl.mlx, texture)))
	{
		mlx_close_window(sl.mlx);
		error();
	}
	if (mlx_image_to_window(sl.mlx, sl.img.player , 0, 0) == -1)
	{
		mlx_close_window(sl.mlx);
		error();
	}

	mlx_loop_hook(sl.mlx, ft_hook, &sl);
	mlx_loop(sl.mlx);
	mlx_terminate(sl.mlx);
	return (EXIT_SUCCESS);
}

/* int	main(int ac, char *av[])
{
	
	
	return (0);
} */