/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:19 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/08 12:08:10 by dcaro-ro         ###   ########.fr       */
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
	t_coord		tex;
	t_xpm		*texture;
	int			color;
	int			(*colors)[3];

	colors = game->mapdata->colors;
	if (y < ray->draw_start)
		color = get_color(colors[0][0], colors[0][1], colors[0][2]);
	else if (y > ray->draw_end)
		color = get_color(colors[1][0], colors[1][1], colors[1][2]);
	else
	{
		texture = select_texture(game, ray);
		tex.y = (y - ray->draw_start) * texture->height / ray->line_height;
		tex.x = (int)(ray->wall_x * (double)texture->width);
		if ((ray->side == 0 && ray->dir.x < 0)
			|| (ray->side == 1 && ray->dir.y > 0))
			tex.x = texture->width - tex.x - 1;
		color = get_texture_color(texture, tex.x, tex.y);
	}
	put_pixel(game, x, y, color);
}

// int	get_texture_color(t_game *game, t_ray *ray, int x, int y)
// {
// 	t_xpm	*texture;
// 	int		tex_x;
// 	int		tex_y;
// 	char	*color_addr;
// 	int		color;

// 	texture = select_texture(game, ray);
// 	if (!texture || x < 0 || x >= texture->width
// 		|| y < 0 || y >= texture->height)
// 		return (0);
// 	tex_x = (int)(ray->wall_x * (double)texture->width);
// 	if ((ray->side == 0 && ray->dir.x < 0)
// 		|| (ray->side == 1 && ray->dir.y > 0))
// 		tex_x = texture->width - tex_x - 1;
// 	tex_y = ((y - ray->draw_start) * texture->height) / ray->line_height;
// 	color_addr = texture->addr
// 		+ (tex_y * texture->size_line + tex_x * (texture->bpp / 8));
// 	color = *(unsigned int *)color_addr;
// 	return (color);
// }

// void	render_pixel(t_game *game, int x, int y, t_ray *ray)
// {
// 	int			color;
// 	int			(*colors)[3];

// 	colors = game->mapdata->colors;
// 	if (y < ray->draw_start)
// 		color = get_color(colors[0][0], colors[0][1], colors[0][2]);
// 	else if (y > ray->draw_end)
// 		color = get_color(colors[1][0], colors[1][1], colors[1][2]);
// 	else
// 		color = get_texture_color(game, ray, x, y);
// 	put_pixel(game, x, y, color);
// }

// void	render_pixel(t_game *game, int x, int y, t_ray *ray)
// {
// 	t_coord		tex;
// 	t_xpm		*texture;
// 	int			color;
// 	t_mapdata	*m;

// 	m = game->mapdata;
// 	if (y < ray->draw_start)
// 		color = get_color(m->colors[0][0], m->colors[0][1], m->colors[0][2]);
// 	else if (y > ray->draw_end)
// 		color = get_color(m->colors[1][0], m->colors[1][1], m->colors[1][2]);
// 	else
// 	{
// 		tex.y = (y - ray->draw_start)
// 			* game->textures->north.height / ray->line_height;
// 		texture = select_texture(game, ray);
// 		tex.x = (int)(ray->wall_x * texture->width);
// 		if ((ray->side == 0 && ray->dir.x < 0)
// 			|| (ray->side == 1 && ray->dir.y > 0))
// 			tex.x = texture->width - tex.x - 1;
// 		color = get_texture_color(texture, tex.x, tex.y);
// 	}
// 	put_pixel(game, x, y, color);
// }
