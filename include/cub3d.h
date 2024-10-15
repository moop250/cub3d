/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/15 15:38:27 by hlibine          ###   ########.fr       */
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

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
}	t_player;

typedef struct s_mapdata
{
	char		**tmp;
	char		**map;
	t_player	player;
	int			colors[2][3];
}	t_mapdata;

typedef struct s_textures
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	int		north_size[2];
	int		south_size[2];
	int		east_size[2];
	int		west_size[2];
}	t_textures;

typedef struct s_game
{
	t_mapdata	*mapdata;
	t_textures	textures;
}	t_game;

void	*parsing(t_game *game, char *lvl_path);
void	ft_error(const char *msg);
void	freeall(t_game *game);

#endif
