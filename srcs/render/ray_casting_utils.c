/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:19 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/04 15:19:11 by dcaro-ro         ###   ########.fr       */
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
	ray->coord.x = 0;
	ray->coord.y = 0;
	ray->step.x = 0.0;
	ray->step.y = 0.0;
	ray->side = 0;
	ray->wall_dist = 0.0;
	ray->wall_x = 0.0;
	ray->hit = false;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_ray_data(t_game *game, t_ray *ray, int x)
{
	t_vector	dir;
	t_vector	plane;

	init_ray(ray);
	ray->cam_x = 2 * x / (double)game->width - 1;
	dir = game->mapdata->player.dir;
	plane = game->mapdata->player.plane;
	ray->dir.x = dir.x + plane.x * ray->cam_x;
	ray->dir.y = dir.y + plane.y * ray->cam_x;
	ray->coord.x = (int)game->mapdata->player.pos.x;
	ray->coord.y = (int)game->mapdata->player.pos.y;
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = false;
}

static void	calc_step_side_dist(t_game *game, t_ray *ray)
{
	t_vector	pos;

	pos = game->mapdata->player.pos;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pos.x - ray->coord.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->coord.x + 1.0 - pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pos.y - ray->coord.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->coord.y + 1.0 - pos.y) * ray->delta_dist.y;
	}
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

int	get_texture_color(t_game *game, t_ray *ray, int x, int y)
{
	t_xpm	*texture;
	int		tex_x;
	int		tex_y;
	char	*color_addr;
	int		color;

	texture = select_texture(game, ray);
	if (!texture || x < 0 || x >= texture->width
		|| y < 0 || y >= texture->height)
		return (0);
	tex_x = (int)(ray->wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->dir.x < 0)
		|| (ray->side == 1 && ray->dir.y > 0))
		tex_x = texture->width - tex_x - 1;
	tex_y = ((y - ray->draw_start) * texture->height) / ray->line_height;
	color_addr = texture->addr
		+ (tex_y * texture->size_line + tex_x * (texture->bpp / 8));
	color = *(unsigned int *)color_addr;
	return (color);
}
