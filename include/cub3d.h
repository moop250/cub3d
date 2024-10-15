/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/15 12:19:53 by dcaro-ro         ###   ########.fr       */
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

// Represents a 2D vector with x and y coordinates
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
 * @param plane Camera plane defining the player's field of view
 * (perpendicular to dir).
 */
typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_mapdata
{
	char		**map;
	t_player	player;
	int			colors[2][3];
}	t_mapdata;

/**
 * Texture structure
 *
 * @param img Pointer to the texture image.
 * @param addr Pointer to the image's memory address.
 * @param bpp Bits per pixel (color depth).
 * @param line_length Number of bytes in each row of the image.
 * @param endian Endian-ness of the pixel data.
 * @param width Texture width.
 * @param height Texture height.
 */
typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_texture;

/**
 * Textures structure
 *
 * @param north Texture for the north-facing wall.
 * @param south Texture for the south-facing wall.
 * @param east Texture for the east-facing wall.
 * @param west Texture for the west-facing wall.
 * @param sprite Texture for any sprites in the game.
 * @param floor Texture for the floor (if used).
 * @param ceiling Texture for the ceiling (if used).
 */
typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_texture	sprite;
	t_texture	floor;
	t_texture	ceiling;
}	t_textures;

/**
 * Game structure
 *
 * @param mapdata Pointer to the map data.
 * @param textures Contains the various textures used in the game.
 */
typedef struct s_game
{
	t_mapdata	*mapdata;
	t_textures	textures;
}	t_game;

void	*parsing(t_game *game, char *lvl_path);
void	ft_error(const char *msg);
void	freeall(t_game *game);

#endif
