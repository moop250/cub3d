/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:06:31 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/14 21:24:19 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture_data(t_img *texture, void *mlx_ptr)
{
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
}

void	init_textures(t_game *game)
{
	init_texture_data(&game->textures->north, game->mlx.ptr);
	init_texture_data(&game->textures->south, game->mlx.ptr);
	init_texture_data(&game->textures->east, game->mlx.ptr);
	init_texture_data(&game->textures->west, game->mlx.ptr);
}

int	get_texture_pixel_color(t_img *texture, int x, int y)
{
	char	*px;
	int		color;

	if (!texture || x < 0 || x >= texture->width
		|| y < 0 || y >= texture->height)
		return (0);
	px = texture->addr + (y * texture->size_line + x * (texture->bpp / 8));
	color = *(unsigned int *)px;
	if (texture->endian != 0)
		color = ((color >> 24) & 0xFF) | ((color >> 8) & 0xFF00)
			| ((color << 8) & 0xFF0000) | ((color << 24) & 0xFF000000);
	return ((int)color);
}

static t_img	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			return (game->textures = &game->textures->west);
		else
			return (game->textures = &game->textures->east);
	}
	else
	{
		if (ray->dir.y < 0)
			return (game->textures = &game->textures->north);
		else
			return (game->textures = &game->textures->south);
	}
}

/* Get the color of the wall texture based on the ray's side
	Assumes all textures have the same height */
int	get_wall_texture_color(t_game *game, t_ray *ray, int y, t_ray_line *line)
{
	int		texture_height;
	int		tex_y;
	int		tex_x;
	int		color;
	t_img	*texture;

	texture_height = game->textures->north.height;
	if (ray->side == 0)
	{
		tex_x = (int)(ray->coord.y * texture_height) % texture_height;
		if (ray->dir.x < 0)
			tex_x = texture_height - tex_x - 1;
	}
	else
	{
		tex_x = (int)(ray->coord.x * texture_height) % texture_height;
		if (ray->dir.y < 0)
			tex_x = texture_height - tex_x - 1;
	}
	tex_y = (int)((y - line->draw_start)
			* (texture_height / (float)line->height));
	texture = select_texture(game, ray);
	color = get_texture_pixel_color(texture, tex_x, tex_y);
	return (color);
}
