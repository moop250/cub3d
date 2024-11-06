/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:27:22 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/06 03:22:51 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	ray->delta_dist.x = sqrt(1 + (ray->dir.y * ray->dir.y)
			/ (ray->dir.x * ray->dir.x));
	ray->delta_dist.y = sqrt(1 + (ray->dir.x * ray->dir.x)
			/ (ray->dir.y * ray->dir.y));
}

void	calc_step_side_dist(t_game *game, t_ray *ray)
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

//Ray casting algorithm
static void	dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->coord.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->coord.y += ray->step.y;
			ray->side = 1;
		}
		//debugging output
		printf("Ray Coord: (%d, %d) | Map Value: %c | Side: %d | Hit: %d\n",
			ray->coord.x, ray->coord.y,
			game->mapdata->map[ray->coord.y][ray->coord.x],
			ray->side, ray->hit);
		if (game->mapdata->map[ray->coord.x][ray->coord.y] > '0')
			ray->hit = 1;
	}
}

static void	calculate_line_height(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->line_height = (int)(game->height / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->height / 2;
	if (ray->draw_end >= game->height)
		ray->draw_end = game->height - 1;
	if (ray->side == 0)
		ray->wall_x = game->mapdata->player.pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = game->mapdata->player.pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

void	ray_casting(t_game *game)
{
	t_ray	ray;
	int		x;
	int		y;

	x = 0;
	while (x < game->width)
	{
		init_ray_data(game, &ray, x);
		calc_step_side_dist(game, &ray);
		dda(game, &ray);
		calculate_line_height(game, &ray);

		y = 0;
		while (y < game->height)
		{
			render_pixel(game, x, y, &ray);
			y++;
		}
		x++;
	}
}
