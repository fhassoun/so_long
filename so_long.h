/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:31:16 by fhassoun          #+#    #+#             */
/*   Updated: 2023/04/13 13:56:38 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
//# include "mlx/mlx.h"

# define WIDTH 512
# define HEIGHT 512

typedef struc collect_s 
{
	mlx_image_t* collect;
	int			x_coll;
	int			y_coll;
} collects_t

typedef struct textures_s
{
	mlx_textures_t* empty;
	mlx_textures_t* wall;
	mlx_textures_t* collectible;
	mlx_textures_t* exit;
	mlx_textures_t* player;
}	textures_t;


typedef struct img_s
{
	mlx_image_t* empty;
	mlx_image_t* wall;
	mlx_image_t* collectible;
	// char		*collectibles[1000];
	mlx_image_t* exit;
	mlx_image_t* player;
}	img_t;

typedef struct sl_s
{
	mlx_t	*mlx;
	img_t	img;
}	sl_t;




#endif