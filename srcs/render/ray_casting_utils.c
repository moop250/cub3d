/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:19 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 18:55:54 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->cam_x = 0.0;
	ray->dir.x = 0.0;
	ray->dir.y = 0.0;
	ray->side_dist.x = 0.0;
	ray->side_dist.y = 0.0;
	ray->delta_dist.x = 0.0;
	ray->delta_dist.y = 0.0;
	ray->map.x = 0;
	ray->map.y = 0;
	ray->step.x = 0.0;
	ray->step.y = 0.0;
	ray->side = 0;
	ray->wall_dist = 0.0;
	ray->wall_x = 0.0;
	ray->hit = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

t_xpm	*select_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			return (&game->textures->west);
		else
			return (&game->textures->east);
	}
	else
	{
		if (ray->dir.y < 0)
			return (&game->textures->north);
		else
			return (&game->textures->south);
	}
}

int	get_texture_color(t_xpm *texture, int tex_x, int tex_y)
{
	int	color;
	int	*px;

	px = (int *)(texture->addr
			+ (tex_y * texture->size_line + tex_x * (texture->bpp / 8)));
	color = *px;
	return (color);
}

void	render_pixel(t_game *game, int x, int y, t_ray *ray)
{
	t_xpm		*texture;
	t_texdata	tex;

	if (y < ray->draw_start)
		put_pixel(game, x, y, game->ceiling_color);
	else if (y > ray->draw_end)
		put_pixel(game, x, y, game->floor_color);
	else
	{
		texture = select_texture(game, ray);
		tex.y = (y - ray->draw_start) * texture->height / ray->line_height;
		tex.x = (int)(ray->wall_x * (double)texture->width);
		if ((ray->side == 0 && ray->dir.x < 0)
			|| (ray->side == 1 && ray->dir.y > 0))
			tex.x = texture->width - tex.x - 1;
		tex.step = 1.0 * texture->height / ray->line_height;
		tex.pos = (ray->draw_start - game->height / 2
				+ ray->line_height / 2) * tex.step;
		tex.pos += (y - ray->draw_start) * tex.step;
		tex.y = (int)tex.pos & (texture->height - 1);
		tex.color = get_texture_color(texture, tex.x, tex.y);
		if (ray->side == 1)
			tex.color = (tex.color >> 1) & 8355711;
		put_pixel(game, x, y, tex.color);
	}
}
