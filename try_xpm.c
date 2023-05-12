/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:09:22 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/12 12:37:19 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// xpm_t* mlx_load_xpm42(const char* path);

void load_empty(t_sl *sl)
{
	sl->textures.empty = mlx_load_xpm42("./pics/grass.xpm");
	if (!sl->textures.empty)
		error_message("Problem with loading png");
	sl->img.empty = mlx_texture_to_image(sl->mlx, sl->textures.empty.texture);
	if (!sl->img.empty)
		error_message("Problem with texture to image");
	mlx_delete_xpm42(sl->textures.empty);
}