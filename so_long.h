/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:31:16 by fhassoun          #+#    #+#             */
/*   Updated: 2023/05/18 10:38:34 by fhassoun         ###   ########.fr       */
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

# define WIDTH 512
# define HEIGHT 512
# define IMG 50

typedef struct s_test {
	xpm_t	*test;
}t_test;

typedef struct s_limits
{
	int	player;
	int	collectables;
	int	collected;
	int	exits;
}	t_limits;

typedef struct s_playerposition
{
	size_t	x;
	size_t	y;
}	t_playerposition;

typedef struct s_textures
{
	xpm_t			*empty;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
}	t_textures;

typedef struct s_img
{
	mlx_image_t	*empty;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}	t_img;

typedef struct s_sl
{
	mlx_t				*mlx;
	t_img				img;
	t_textures			textures;
	char				*filename;
	char				*map_string;
	char				**grid;
	int					map_width;
	int					map_height;
	int					moves;
	t_limits			limits;
	t_playerposition	ppos;
	t_test				test;
}	t_sl;

//images.c
void		load_player(t_sl *sl);
void		load_empty(t_sl *sl);
void		load_exit(t_sl *sl);
void		load_wall(t_sl *sl);
void		load_collectible(t_sl *sl);
//load_map.c
void		load_background(t_sl *sl);
void		image_select(t_sl *sl, int y, int x);
void		create_map(t_sl *sl);
//main.c
void		my_hook(mlx_key_data_t keydata, void *param);
void		init_game(t_sl *sl);
void		cleanup(t_sl *sl);
//map_checker.c
int			check_border(t_sl *sl);
int			check_content(t_sl *sl);
int			check_limits(t_sl *sl);
int			check_extension(char *file);
int			check_rect(t_sl *sl);
//map_utils.c
int			check_map(t_sl *sl);
void		too_many_lines(t_sl *sl);
//maps.c
void		get_dimensions(t_sl *sl);
int			check_newline(char *map_string);
void		too_long_again(t_sl *sl, char *line, int fd);
int			parse_map(char *map, t_sl *sl);
//move.c
void		delete_collectible(t_sl *sl, int y, int x);
void		move_up(t_sl *sl);
void		move_down(t_sl *sl);
void		move_right(t_sl *sl);
void		move_left(t_sl *sl);
//path_checker.c
void		free_grid(char **grid, size_t height);
int			flood_fill(t_sl *tmp, int y, int x);
int			check_path(t_sl *sl);
//so_long_utils.c
void		error(void);
void		error_message(char *message);
void		load_textures(t_sl *sl);
void		game_over(t_sl *sl);

#endif