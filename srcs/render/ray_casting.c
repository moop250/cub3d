/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:27:22 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/21 14:56:22 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * Digital  Differential Analysis (DDA)
 *
 * Determines the point of intersection with a wall
 * in the map. Updates the ray's side, hit, and map
 * position based on the intersection.
 *
 * Move in the direction of the smallest side distance:
 * if (ray->side_dist.x < ray->side_dist.y)
 * Increment x-side distance
 * Move one step in x-direction
 * ray->side = 0 (vertical wall hit)
 * else:
 * Increment x-side distance
 * Move one step in x-direction
 * ray->side = 1 (horizontal wall hit)
 */
static void	dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (game->mapdata->map[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

/**
 * Calculates the height and position of the line to be rendered
 * for the ray.
 * Determines where the line starts and ends, as well as the
 * precise texture coordinate of the wall hit.
 *
 * Calculate the perpendicular wall distance based on the side
 * of the wall hit.
 * Calculate the height of the line to draw on the screen
 * Calculate where the line starts on the screen
 * Determine the exact x-coordinate of the wall hit for texture mapping
 * Remove the integer part to keep only the fractional value to
 * calculate the exact position of the wall hit on the texture
 */
static void	calc_line_height(t_game *game, t_ray *ray)
{
	t_vector	pos;

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
	pos = game->mapdata->player.pos;
	if (ray->side == 0)
		ray->wall_x = pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = pos.x + ray->wall_dist * ray->dir.x;
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
		init_ray(game, &ray, x);
		dda(game, &ray);
		calc_line_height(game, &ray);
		y = 0;
		while (y < game->height)
		{
			render_pixel(game, &ray, x, y);
			y++;
		}
		x++;
	}
}
