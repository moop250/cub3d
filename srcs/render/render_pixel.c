/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:07:07 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 15:43:52 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// // void	normalize_x_coord(t_game *game, t_ray *ray)
// // {
// // 	t_vector	pos;

// // 	pos = game->mapdata->player.pos;
// // 	if (ray->side == 0)
// // 		ray->wall_x = pos.y + ray->wall_dist * ray->dir.y;
// // 	else
// // 		ray->wall_x = pos.x + ray->wall_dist * ray->dir.x;
// // 	ray->wall_x -= floor(ray->wall_x);
// // }

// // int	get_tex_pixel_color(t_game *game, t_tex_id id, int x, int y)
// // {
// // 	// if (x >= 0 && x < TEX_WIDTH && y >= 0 && y < TEX_HEIGHT)
// // 		return (game->tex_pixels[id][y * TEX_WIDTH + x]);
// // 	// return (0);
// // }

// void	render_pixel(t_game *game, t_ray *ray, int x, int y)
// {
// 	t_xpm	*texture;
// 	int		color;

// 	if (y < ray->draw_start)
// 		color = game->ceiling_color;
// 	else if (y > ray->draw_end)
// 		color = game->floor_color;
// 	else
// 	{
// 		texture = get_current_texture(game, ray);
// 		//normalize_x_coord(game, ray);
// 		ray->tex_x = (int)(ray->wall_x * (double)texture->width);
// 		if ((ray->side == 0 && ray->dir.x < 0)
// 			|| (ray->side == 1 && ray->dir.y > 0))
// 			ray->tex_x = texture->width - ray->tex_x - 1;
// 		// ray->tex_step = 1.0 * (double)texture->height / ray->line_height;
// 		// ray->tex_pos = (ray->draw_start - game->height / 2
// 		// 		+ ray->line_height / 2) * ray->tex_step;
// 		// ray->tex_y = (int)ray->tex_pos & (texture->height - 1);
// 		// ray->tex_pos += ray->tex_step;

// 		ray->tex_y = (int)(y - ray->draw_start) * texture->height
// 			/ (ray->draw_end - ray->draw_start);
// 		color = game->tex_pixels[game->current_tex][ray->tex_y * texture->width + ray->tex_x];
// 		if (ray->side == 1)
// 			color = (color >> 1) & 8355711;
// 	}
// 	put_pixel(game, x, y, color);
// }






// void	render_pixel(t_game *game, t_ray *ray, int x, int y)
// {
// 	t_xpm	*texture;
// 	int		color;
// 	int		new_y;

// 	if (y < ray->draw_start)
// 		put_pixel(game, x, y, game->ceiling_color);
// 	else if (y > ray->draw_end)
// 		put_pixel(game, x, y, game->floor_color);
// 	else
// 	{
// 		texture = get_current_texture(game, ray);
// 		ray->tex_x = (int)(ray->wall_x * (double)texture->width);
// 		if ((ray->side == 0 && ray->dir.x < 0)
// 			|| (ray->side == 1 && ray->dir.y > 0))
// 			ray->tex_x = texture->width - ray->tex_x - 1;
// 		ray->tex_step = 1.0 * (double)texture->height / ray->line_height;
// 		ray->tex_pos = (ray->draw_start - game->height / 2 + ray->line_height / 2)
// 		* ray->tex_step;
// 		new_y = ray->draw_start;
// 		while (new_y < ray->draw_end)
// 		{
// 			ray->tex_y = (int)ray->tex_pos & (texture->height - 1);
// 			ray->tex_pos += ray->tex_step;
// 			color = game->tex_pixels[game->current_tex][ray->tex_y
// 				* texture->width + ray->tex_x];
// 			if (ray->side == 1)
// 				color = (color >> 1) & 8355711;
// 			put_pixel(game, x, new_y, color);
// 			new_y++;
// 		}
// 	}
// }

// works for default, doesn't work for dungeon

void	draw_ceiling(t_game *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		put_pixel(game, x, y, game->ceiling_color);
		y++;
	}
}

void	draw_floor(t_game *game, int x, int draw_end)
{
	int	y;

	y = draw_end + 1;
	while (y < game->height)
	{
		put_pixel(game, x, y, game->floor_color);
		y++;
	}
}

// void	draw_wall_texture(t_game *game, t_xpm *texture, t_ray *ray, int x)
// {
// 	int	y;
// 	int	color;

// 	ray->tex_step = 1.0 * (double)texture->height / ray->line_height;
// 	ray->tex_pos = (ray->draw_start - game->height / 2 + ray->line_height / 2)
// 		* ray->tex_step;
// 	y = ray->draw_start;
// 	while (y < ray->draw_end)
// 	{
// 		ray->tex_y = (int)ray->tex_pos & (texture->height - 1);
// 		ray->tex_pos += ray->tex_step;
// 		color = game->tex_pixels[game->current_tex][ray->tex_y
// 			* texture->width + ray->tex_x];
// 		if (ray->side == 1)
// 			color = (color >> 1) & 8355711;
// 		if (color > 0)
// 		{
// 			//game->tex_pixels[y][x] = color;
// 			put_pixel(game, x, y, color);
// 		}
// 		y++;
// 	}
// }

void	draw_wall_texture(t_game *game, t_xpm *texture, t_ray *ray, int x)
{
	int	y;
	int	color;

	ray->tex_step = 1.0 * (double)texture->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - game->height / 2 + ray->line_height / 2)
		* ray->tex_step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (texture->height - 1);
		ray->tex_pos += ray->tex_step;
		color = game->tex_pixels[game->current_tex][texture->width
			* ray->tex_y + ray->tex_x];
		put_pixel(game, x, y, color);
		// if (game->current_tex == NO || game->current_tex == EA)
		// 	color = (color >> 1) & 8355711;
		// if (color > 0)
		// {
		// 	game->tex_pixels[game->current_tex][texture->width
		// 		* ray->tex_y + ray->tex_x] = color;
		// 	put_pixel(game, x, y, color);
		// }
		y++;
	}
}

void	render_pixel(t_game *game, t_ray *ray, int x)
{
	t_xpm	*texture;

	texture = get_current_texture(game, ray);
	ray->tex_x = (int)(ray->wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->dir.x < 0)
		|| (ray->side == 1 && ray->dir.y > 0))
		ray->tex_x = texture->width - ray->tex_x - 1;
	draw_ceiling(game, x, ray->draw_start);
	draw_wall_texture(game, texture, ray, x);
	draw_floor(game, x, ray->draw_end);
}
