/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:07:07 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/14 20:21:02 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_tex_pixel_color(t_game *game, t_tex_id id, int x, int y)
{
	if (x >= 0 && x < TEX_WIDTH && y >= 0 && y < TEX_HEIGHT)
		return (game->tex_pixels[id][y * TEX_WIDTH + x]);
	return (0);
}

// Calculate the color with shading based on the wall distance
// static int	calculate_shaded_color(int color, double wall_dist)
// {
// 	double	shading_factor;
// 	int		red;
// 	int		green;
// 	int		blue;

// 	shading_factor = 1.0 / (1.0 + wall_dist * 0.2);
// 	red = ((color >> 16) & 0xFF) * shading_factor;
// 	green = ((color >> 8) & 0xFF) * shading_factor;
// 	blue = (color & 0xFF) * shading_factor;
// 	red = ft_clamp((int)(((color >> 16) & 0xFF) * shading_factor), 0, 255);
// 	green = ft_clamp((int)(((color >> 8) & 0xFF) * shading_factor), 0, 255);
// 	blue = ft_clamp((int)((color & 0xFF) * shading_factor), 0, 255);
// 	return ((red << 16) | (green << 8) | blue);
// }

int	adjust_brightness(int color, double factor)
{
	int		red;
	int		green;
	int		blue;

	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = color & 0xFF;
	red = ft_clamp((int)(red * factor), 0, 255);
	green = ft_clamp((int)(green * factor), 0, 255);
	blue = ft_clamp((int)(blue * factor), 0, 255);
	return ((red << 16) | (green << 8) | blue);
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
			color = adjust_brightness(color, 0.7);
			//color = (color >> 1) & 8355711;
	}
	put_pixel(game, x, y, color);
}
