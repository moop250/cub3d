/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:27:22 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/04 15:21:23 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//Ray casting algorithm
static void	dda(t_game *game, t_ray *ray)
{
	while (ray->hit == false)
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
		if (game->mapdata->map[ray->coord.y][ray->coord.x] == '1')
			ray->hit = true;
	}
	if (ray->side == 0)
		ray->wall_dist = (ray->coord.x - game->mapdata->player.pos.x
				+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->wall_dist = (ray->coord.y - game->mapdata->player.pos.y
				+ (1 - ray->step.y) / 2) / ray->dir.y;
}

static void	calculate_line_height(t_game *game, t_ray *ray)
{
	t_player	*player;

	player = &game->mapdata->player;
	if (ray->side == 0)
		ray->wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

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
		y = ray.draw_start;
		while (y < ray.draw_end)
		{
			game->pixels[y][x] = get_texture_color(game, &ray, x, y);
			put_pixel(game, x, y, game->pixels[y][x]);
			y++;
		}
		x++;
	}
}
