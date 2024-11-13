/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:07:07 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 17:12:13 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	normalize_x_coord(t_game *game, t_ray *ray)
// {
// 	t_vector	pos;

// 	pos = game->mapdata->player.pos;
// 	if (ray->side == 0)
// 		ray->wall_x = pos.y + ray->wall_dist * ray->dir.y;
// 	else
// 		ray->wall_x = pos.x + ray->wall_dist * ray->dir.x;
// 	ray->wall_x -= floor(ray->wall_x);
// }

int	get_tex_pixel_color(t_game *game, t_tex_id id, int x, int y)
{
	if (x >= 0 && x < TEX_WIDTH && y >= 0 && y < TEX_HEIGHT)
		return (game->tex_pixels[id][y * TEX_WIDTH + x]);
	return (0);
}

void	render_pixel(t_game *game, t_ray *ray, int x, int y)
{
	t_xpm	*texture;
	int		color;

	if (y < ray->draw_start)
		color = game->ceiling_color;
	else if (y > ray->draw_end)
		color = game->floor_color;
	else
	{
		texture = get_current_texture(game, ray);
		ray->tex_x = (int)(ray->wall_x * (double)texture->width);
		if ((ray->side == 0 && ray->dir.x < 0)
			|| (ray->side == 1 && ray->dir.y > 0))
			ray->tex_x = texture->width - ray->tex_x - 1;
		ray->tex_step = 1.0 * texture->height / ray->line_height;
		ray->tex_pos = (ray->draw_start - game->height / 2
				+ ray->line_height / 2) * ray->tex_step;
		ray->tex_pos += (y - ray->draw_start) * ray->tex_step;
		ray->tex_y = (int)ray->tex_pos & (texture->height - 1);
		color = get_tex_pixel_color(game, game->tex_id, ray->tex_x, ray->tex_y);
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
	}
	put_pixel(game, x, y, color);
}
