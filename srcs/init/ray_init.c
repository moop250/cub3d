/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:39:24 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 12:18:58 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	setup_ray(t_ray *ray)
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
	// ray->tex_x = 0;
	// ray->tex_y = 0;
	// ray->tex_pos = 0.0;
	// ray->tex_step = 0.0;
}

static void	init_ray_data(t_game *game, t_ray *ray, int x)
{
	t_vector	dir;
	t_vector	plane;

	dir = game->mapdata->player.dir;
	plane = game->mapdata->player.plane;
	setup_ray(ray);
	ray->cam_x = 2 * x / (double)game->width - 1;
	ray->dir.x = dir.x + plane.x * ray->cam_x;
	ray->dir.y = dir.y + plane.y * ray->cam_x;
	ray->map.x = (int)game->mapdata->player.pos.x;
	ray->map.y = (int)game->mapdata->player.pos.y;
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

static void	calc_step_side_dist(t_game *game, t_ray *ray)
{
	t_vector	pos;

	pos = game->mapdata->player.pos;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - pos.y) * ray->delta_dist.y;
	}
}

void	init_ray(t_game *game, t_ray *ray, int x)
{
	init_ray_data(game, ray, x);
	calc_step_side_dist(game, ray);
}
