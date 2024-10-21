/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/21 13:26:02 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/include/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# ifdef __APPLE__
#  include "../libs/minilibx_opengl/mlx.h"
# endif

# ifndef __APPLE__
#  include "../libs/minilibx-linux/mlx.h"
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif

# define GAME_ERR_MALLOC "Could not allocate memory for game structure"
# define GAME_PIX_ERR "Could not allocate memory for pixel array"

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

/**
 * Player structure
 *
 * @param pos Player's position in the map.
 * @param dir Player's POV or direction (which whay the player is facing).
 * @param plane 2D vector representing the camera plane.
 */
typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

/**
 * Player structure
 *
 * @param tmp Temporary map storage.
 * @param map Parsed map representation.
 * @param player Player information (position, direction, etc.)
 * @param colors[2][3] Floor and ceiling colors.
 */
typedef struct s_mapdata
{
	char		**tmp;
	char		**map;
	t_player	player;
	int			colors[2][3];
}	t_mapdata;

/**
 * XPM image structure
 *
 * @param img Image pointer.
 * @param width Image width.
 * @param height Image height.
 */
typedef struct s_xmp
{
	void	*img;
	int		width;
	int		height;
}			t_xmp;

/**
 * Textures structure
 *
 * @param north North wall texture.
 * @param south South wall texture.
 * @param east East wall texture.
 * @param west West wall texture.
 */
typedef struct s_textures
{
	t_xmp	north;
	t_xmp	south;
	t_xmp	east;
	t_xmp	west;
}			t_textures;

/**
 * MLX structure
 *
 * @param mlx MLX pointer.
 * @param mlx_window MLX window pointer.
 */
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}			t_mlx;

/**
 * Game structure
 *
 * @param mapdata Map data (map, player, colors).
 * @param textures Wall textures.
 * @param mlx MiniLibX related data.
 * @param width Screen width in pixels.
 * @param height Screen height in pixels.
 * @param pixels 2D buffer for storing pixel colors.
 */
typedef struct s_game
{
	t_mapdata	*mapdata;
	t_textures	*textures;
	t_mlx		mlx;
	int			width;
	int			height;
	int			**pixels;
}	t_game;

void	*parsing(t_game *game, char *lvl_path);
void	ft_error(const char *msg);
void	freeall(t_game *game);
void	clean_map(char **map);

#endif
