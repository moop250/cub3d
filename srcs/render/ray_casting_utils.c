/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:19 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 16:36:31 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*px;
	int		size_line;

	size_line = game->mlx.size_line;
	if (x >= 0 && x < game->width && y >= 0 && y < game->height)
	{
		px = game->mlx.addr + (y * size_line + x * (game->mlx.bpp / 8));
		*(unsigned int *)px = color;
	}
}

static t_xpm	*set_texture(t_game *game, t_tex_id id, t_xpm *texture)
{
	game->tex_id = id;
	return (texture);
}

t_xpm	*get_current_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			return (set_texture(game, WE, &game->textures->west));
		else
			return (set_texture(game, EA, &game->textures->east));
	}
	else
	{
		if (ray->dir.y < 0)
			return (set_texture(game, NO, &game->textures->north));
		else
			return (set_texture(game, SO, &game->textures->south));
	}
}


// void	draw_wall(t_game *game, t_xpm *texture, t_ray *ray, int x)
// {
// 	int	y;
// 	int	color;

// 	ray->tex_step = 1.0 * (double)texture->height / ray->line_height;
// 	ray->tex_pos = (ray->draw_start - game->height / 2 + ray->line_height / 2)
// 		* ray->tex_step;
// 	y = ray->draw_start;
// 	while (y < ray->draw_end)
// 	{
// 		ray->tex_y = (int)ray->tex_pos & (texture->height - 1);
// 		ray->tex_pos += ray->tex_step;
// 		// color = texture->addr[texture->size_line * ray->tex_y + ray->tex_x];
// 		color = *(int *)(texture->addr + (ray->tex_y
// 					* texture->size_line + ray->tex_x * (texture->bpp / 8)));
// 		if (ray->side == 1)
// 			color = (color >> 1) & 8355711;
// 		if (color > 0)
// 		{
// 			game->tex_pixels[y][x] = color;
// 			put_pixel(game, x, y, color);
// 		}
// 		y++;
// 	}
// }


// void	update_texture_pixels(t_game *game, t_ray *ray, int x)
// {
// 	t_xpm	*texture;
// 	int		y;
// 	int		color;

// 	texture = get_current_texture(game, ray);
// 	game->tex.x = (int)(ray->wall_x * texture->width);
// 	if ((ray->side == 0 && ray->dir.x < 0)
// 		|| (ray->side == 1 && ray->dir.y > 0))
// 		game->tex.x = texture->width - game->tex.x - 1;
// 	game->tex_step = 1.0 * texture->height / ray->line_height;
// 	game->tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2)
// 		* game->tex_step;
// 	y = ray->draw_start;
// 	while (y < ray->draw_end)
// 	{
// 		game->tex.y = (int)game->tex_pos & (texture->height - 1);
// 		game->tex_pos += game->tex_step;
// 		color = game->tex_pixels[game->tex_id][texture->width
// 			* game->tex.y + game->tex.x];
// 		if (game->current_tex == NO || game->tex_id == EA)
// 			color = (color >> 1) & 8355711;
// 		if (color > 0)
// 			game->tex_pixels[y][x] = color;
// 		y++;
// 	}
// }
