/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:58:19 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/17 10:48:33 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*px;

	px = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)px = color;
}

static t_img	*set_texture(t_game *game, t_tex_id id, t_img *texture)
{
	game->tex_id = id;
	return (texture);
}

t_img	*get_current_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			return (set_texture(game, WE, &game->textures->west));
		else
			return (set_texture(game, EA, &game->textures->east));
	}
	else
	{
		if (ray->dir.y < 0)
			return (set_texture(game, NO, &game->textures->north));
		else
			return (set_texture(game, SO, &game->textures->south));
	}
}

// void	put_pixel(t_game *game, int x, int y, int color)
// {
// 	char	*px;
// 	int		size_line;

// 	size_line = game->mlx.img.size_line;
// 	if (x >= 0 && x < game->width && y >= 0 && y < game->height)
// 	{
// 		px = game->mlx.img.addr + (y * size_line + x * (game->mlx.img.bpp / 8));
// 		*(unsigned int *)px = color;
// 	}
// }
