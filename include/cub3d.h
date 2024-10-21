/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/21 15:44:38 by hlibine          ###   ########.fr       */
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

typedef struct s_xpm
{
	void	*img;
	int		width;
	int		height;
}			t_xpm;

typedef struct s_textures
{
	t_xpm	north;
	t_xpm	south;
	t_xpm	east;
	t_xpm	west;
}			t_textures;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_window;
}			t_mlx;

typedef struct s_game
{
	t_mapdata	*mapdata;
	t_textures	*textures;
	t_mlx		mlx;
}				t_game;

void	*parsing(t_game *game, char *lvl_path);
void	ft_error(const char *msg);
void	freeall(void);

#endif
