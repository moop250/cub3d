/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:19 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/25 19:22:15 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_ray_data(t_game *game, t_ray *ray, int x)
{
	double	cam_x;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	cam_x = 2 * x / (double)game->width - 1;
	dir_x = game->mapdata->player.dir.x;
	dir_y = game->mapdata->player.dir.y;
	plane_x = game->mapdata->player.plane.x;
	plane_y = game->mapdata->player.plane.y;
	ray->dir.x = dir_x + plane_x * cam_x;
	ray->dir.y = dir_y + plane_y * cam_x;
	ray->coord.x = (int)game->mapdata->player.pos.x;
	ray->coord.y = (int)game->mapdata->player.pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = false;
}

static void	calc_step_side_dist(t_game *game, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (game->mapdata->player.pos.x - ray->coord.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->coord.x + 1.0 - game->mapdata->player.pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (game->mapdata->player.pos.y - ray->coord.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->coord.y + 1.0 - game->mapdata->player.pos.y)
			* ray->delta_dist.y;
	}
}

void	init_ray(t_game *game, t_ray *ray, int x)
{
	init_ray_data(game, ray, x);
	calc_step_side_dist(game, ray);
}
