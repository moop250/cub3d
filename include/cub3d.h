/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/06 17:37:46 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/include/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "keycodes.h"

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

# define PI 3.14159265358979323846
# define HALF_PI 1.57079632679489661923
# define STEP_SIZE 0.1

# define WHITESPACE " \n\t"
# define MAP_CHARS "01NSEW"
# define SPAWN_CHARS "NSEW"
# define COLOR_CHARS "0123456789,"

# ifndef FILE_SUFFIX
#  define FILE_SUFFIX ".cub"
# endif

# define GAME_ERR_MALLOC "Could not allocate memory for game structure"
# define GAME_PIX_ERR "Could not allocate memory for pixel array\n"
# define COLOR_ERR_CHAR "Unauthorized character in color"

# define RAY_LIGHT_COLOR 0x007F0000
# define RAY_DARK_COLOR 0x00FF0000

# ifndef FT_PI
#  define FT_PI 3.14159265358979323846
# endif

# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.1
# define ROTATION_DEGREE 5.0
# define MAX_DIRTY_RECTS 64

typedef struct s_indexes
{
	int		i;
	int		j;
	int		k;
}	t_indexes;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef enum e_move
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
}	t_move;

/**
 * Player structure
 *
 * @param pos Player's position in the map.
 * @param dir 2D vector used to calculate movement based on the angle.
 * @param angle The angle of the player (which whay the player is facing).
 * @param plane 2D vector representing the camera plane.
 */
typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	double		angle;
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
 * XPM structure
 *
 * @param img Image pointer.
 * @param width Width of the texture in px.
 * @param height Height of the texture in px.
 * @param addr Address of the pixel data.
 * @param bpp Bits per pixel.
 * @param size_line Size of a line (number of bytes per row in the texture).
 * @param endian Endianess.
 * @param path Path to the XPM file.
 */
typedef struct s_xpm
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_xpm;

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
	t_xpm	north;
	t_xpm	south;
	t_xpm	east;
	t_xpm	west;
}	t_textures;

/**
 * MLX structure
 *
 * @param ptr MLX pointer.
 * @param win_ptr MLX window pointer.
 * @param img_ptr MLX image pointer.
 * @param addr Image address.
 * @param bpp Bits per pixel.
 * @param size_line Size of a line in bytes.
 * @param endian Endianess.
 */
typedef struct s_mlx
{
	void	*ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_mlx;

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
	t_mapdata		*mapdata;
	t_textures		*textures;
	t_mlx			mlx;
	int				width;
	int				height;
	int				**pixels;
}	t_game;

/**
 * Ray structure
 *
 * @param cam_x Camera X position.
 * @param dir Ray direction.
 * @param side_dist Distance to the first side of the wall.
 * @param delta_dist Distance between two sides of the wall.
 * @param map Current ray coordinates.
 * @param step Step to take in x and y direction (either -1 or 1).
 * @param wall_dist Distance from the player to the wall.
 * @param wall_x Exact position of the wall hit.
 * @param side Side of the wall hit (0 for horizontal, 1 for vertical).
 * @param hit Flag indicating if the ray hit a wall.
 * @param line_height Height of the wall line to draw.
 * @param draw_start Start of the wall line to draw.
 * @param draw_end End of the wall line to draw.
 */
typedef struct s_ray
{
	double		cam_x;
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_coord		coord;
	t_vector	step;
	int			side;
	double		wall_dist;
	double		wall_x;
	int			hit;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

/* Parsing */
char	**file_parser(char *file_path);
int		check_walls(char **map, t_player *player);
void	parse_map(t_game *game, char **file, char *path);
void	parse_textures(t_game *game);
bool	check_map_line(char *line);
void	clean_map(char **map);
bool	parse_colors(t_game *game, char **file_content);
void	*parsing(t_game *game, char *lvl_path);

/* Game */
bool	game_init(t_game *game);

/* Movement */
void	move_player(t_game *game, t_move dir);
void	rotate_player(t_game *game, t_move dir);

//void	render_scene(t_game *game);
void	game_play(t_game *game);

/* Rendering */
void	init_ray(t_ray *ray);
int		get_color(int red, int green, int blue);
void	put_pixel(t_game *game, int x, int y, int color);
void	render_pixel(t_game *game, int x, int y, t_ray *ray);
void	ray_casting(t_game *game);

/* Cleanup */
void	freeall(void);
void	freemlx(t_mlx mlx);
void	*free_pixels(int **pixels, unsigned int rows);
void	*mlx_cleanup(t_game *game);
void	*cleanup_game(t_game *game);

/* errors */
void	ft_error(const char *msg);
void	*ft_free_msg(void *ptr, char *msg);
bool	ft_free_bool(void *ptr, char *msg, bool flag);

/* Debug */
void	print_game(t_game *game);

#endif
