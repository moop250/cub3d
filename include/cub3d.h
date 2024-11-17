/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/17 12:40:32 by dcaro-ro         ###   ########.fr       */
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
# include <X11/X.h>
# include <sys/time.h>
# include <X11/X.h>
# include <sys/time.h>
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
# define TWO_PI 6.28318530717958647692
//# define STEP_SIZE 0.1

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
# define TEX_MALLOC_ERR "Could not allocate memore for texture buffer"
# define TEX_INIT_ERR "Could not initialize texture pixels"

# define RAY_LIGHT_COLOR 0x007F0000
# define RAY_DARK_COLOR 0x00FF0000

# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.05
# define ROTATION_DEGREE 5.0

/* 0.016 == 60 fps (1 / 60) */
# define FRAME_TIME 0.016

# define MIN_DISTANCE 0.001

# define TEX_SIZE 64
# define NUM_TEXTURES 4
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# ifndef BONUS_FLAG
#  if defined(BONUS)
#   define BONUS_FLAG true
#  else
#   define BONUS_FLAG false
#  endif
# endif

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
	RIGHT,
	TURN_LEFT,
	TURN_RIGHT
}	t_move;

typedef enum e_tex_id
{
	NO,
	SO,
	WE,
	EA
}	t_tex_id;

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
 * mapdata structure
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
typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

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
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
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
	//void	*img_ptr;
	//char	*addr;
	//int		bpp;
	//int		size_line;
	//int		endian;
	t_img	img;
	void	*tmp_img;
	char	*tmp_addr;
}	t_mlx;

typedef struct s_move_bools
{
	bool	forward;
	bool	backward;
	bool	left;
	bool	right;
	bool	is_moving;
	bool	rotate_right;
	bool	rotate_left;
	bool	is_rotating;
}	t_move_bools;

/**
 * Bresenham structure
 *
 * @param dx Delta x.
 * @param dy Delta y.
 * @param sx Step x.
 * @param sy Step y.
 * @param error Error.
 * @param e2 Error 2.
 */
typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;
	int	e2;
}	t_bresenham;

typedef struct s_minimap
{
	t_img	img;
	int		width;
	int		height;
}	t_minimap;

/**
 * Game structure
 *
 * @param mapdata Map data (map, player, colors).
 * @param mlx MiniLibX related data.
 * @param width Screen width in pixels.
 * @param height Screen height in pixels.
 * @param floor_color Floor color.
 * @param ceiling_color Ceiling color.
 * @param textures Wall textures.
 * @param tex_id Current texture.
 * @param tex Array of textures.
 * @param tex_pixels Array of texture pixels.
 *
*/
typedef struct s_game
{
	t_mapdata		*mapdata;
	t_mlx			mlx;
	int				width;
	int				height;
	int				floor_color;
	int				ceiling_color;
	t_textures		*textures;
	t_tex_id		tex_id;
	t_img			*tex[NUM_TEXTURES];
	int				*tex_pixels[NUM_TEXTURES];
	t_move_bools	move;
	double			last_time;
	bool			bonus;
	t_minimap		minimap;
}	t_game;

/**
 * Ray structure
 *
 * @param cam_x Camera X position.
 * @param dir Ray direction.
 * @param side_dist Distance to the side of the wall.
 * @param delta_dist Distance between two consecutive x or y intersections.
 * @param map Map coordinates.
 * @param step Step vector.
 * @param side Side of the wall hit.
 * @param wall_dist Distance to the wall.
 * @param wall_x X coordinate of the wall hit.
 * @param hit Flag indicating if the ray hit a wall.
 * @param pitch Pitch of the ray.
 * @param line_height Height of the wall slice to draw.
 * @param draw_start Start of the wall slice to draw.
 * @param draw_end End of the wall slice to draw.
 * @param tex_x X coordinate of the texture.
 * @param tex_y Y coordinate of the texture.
 * @param tex_pos Position in the texture.
 * @param tex_step Step in the texture.
 */
typedef struct s_ray
{
	double		cam_x;
	t_vector	dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_coord		map;
	t_vector	step;
	int			side;
	double		wall_dist;
	double		wall_x;
	int			hit;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	double		tex_step;
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

/* Cleanup */
void	freeall(void);
void	freemlx(t_mlx mlx);
//void	*free_pixels(int **pixels, unsigned int rows);
void	*mlx_cleanup(t_game *game);
void	*destroy_textures(t_game *game);
void	*cleanup_game(t_game *game);
bool	bcleanup_game(t_game *game, char *msg, bool flag);

/* errors */
void	ft_error(const char *msg);

/* Utils */
void	*ft_free_msg(void *ptr, char *msg);
bool	ft_free_bool(void *ptr, char *msg, bool flag);
int		get_color(int red, int green, int blue);

/* init */
bool	game_init(t_game *game);
void	init_ray(t_game *game, t_ray *ray, int x);
void	init_bonus(t_game *game);

/* rendering */
//void	put_pixel(t_game *game, int x, int y, int color);
void	put_pixel(t_img *img, int x, int y, int color);
t_img	*get_current_texture(t_game *game, t_ray *ray);
void	render_pixel(t_game *game, t_ray *ray, int x, int y);
// void	render_pixel(t_game *game, t_ray *ray, int x);
void	ray_casting(t_game *game);
int		game_play(t_game *game);
//void	draw_minimap(t_game *game);

/* Movement and key events */

void	move_player(t_game *game, t_move dir);
void	rotate_player(t_game *game, t_move dir);
int		exit_game(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
int		key_hook_up(int keycode, t_game *game);

/* Time */
double	get_current_time(void);

/* Debug */
void	print_game(t_game *game);

#endif
