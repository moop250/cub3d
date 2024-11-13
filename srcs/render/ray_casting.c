/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:27:22 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 18:51:41 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

static void	calc_line_height(t_game *game, t_ray *ray)
{
	t_vector	pos;

	if (ray->side == 0)
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	pos = game->mapdata->player.pos;
	if (ray->side == 0)
		ray->wall_x = pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

// static void	calc_line_height(t_ray *ray)
// {
// 	if (ray->side == 0)
// 		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
// 	else
// 		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
// 	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
// 	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
// 	if (ray->draw_start < 0)
// 		ray->draw_start = 0;
// 	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
// 	if (ray->draw_end >= WIN_HEIGHT)
// 		ray->draw_end = WIN_HEIGHT - 1;
// }


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
		// calc_line_height(&ray);
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

// void	ray_casting(t_game *game)
// {
// 	t_ray	ray;
// 	int		x;

// 	x = 0;
// 	while (x < game->width)
// 	{
// 		init_ray(game, &ray, x);
// 		dda(game, &ray);
// 		// calc_line_height(&ray);
// 		calc_line_height(game, &ray);
// 		render_pixel(game, &ray, x);
// 		x++;
// 	}
// }
