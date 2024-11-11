/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:27:22 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/25 19:26:58 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Ray casting algorithm
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

static int	calculate_line_height(t_game *game, t_ray *ray,
	int *draw_start, int *draw_end)
{
	int	line_height;

	line_height = (int)(game->height / ray->wall_dist);
	*draw_start = -line_height / 2 + game->height / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + game->height / 2;
	if (*draw_end >= game->height)
		*draw_end = game->height - 1;
	return (line_height);
}

// Calculate the color with shading based on the wall distance
static int	calculate_shaded_color(int color, double wall_dist)
{
	double	shading_factor;
	int		red;
	int		green;
	int		blue;

	shading_factor = 1.0 / (1.0 + wall_dist);
	red = ((color >> 16) & 0xFF) * shading_factor;
	green = ((color >> 8) & 0xFF) * shading_factor;
	blue = (color & 0xFF) * shading_factor;
	red = ft_clamp((int)(((color >> 16) & 0xFF) * shading_factor), 0, 255);
	green = ft_clamp((int)(((color >> 8) & 0xFF) * shading_factor), 0, 255);
	blue = ft_clamp((int)((color & 0xFF) * shading_factor), 0, 255);
	return ((red << 16) | (green << 8) | blue);
}

void	render_ray(t_game *game, t_ray *ray)
{
	int			color;
	int			shaded_color;
	int			x;
	int			y;
	t_ray_line	ray_line;

	ray_line.height = calculate_line_height(game, ray,
			&ray_line.draw_start, &ray_line.draw_end);
	if (ray->side == 1)
		color = RAY_LIGHT_COLOR;
	else
		color = RAY_DARK_COLOR;
	shaded_color = calculate_shaded_color(color, ray->wall_dist);
	y = ray_line.draw_start;
	while (y <= ray_line.draw_end)
	{
		x = ray->coord.x;
		if (y >= 0 && y < game->height && x >= 0 && x < game->width)
			game->pixels[y][ray->coord.x] = shaded_color;
		y++;
	}
}

void	ray_casting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < game->width)
	{
		init_ray(game, &ray, x);
		dda(game, &ray);
		render_ray(game, &ray);
		x++;
	}
}
