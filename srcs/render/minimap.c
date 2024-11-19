/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:39:06 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/19 16:31:00 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	put_map_pixel(t_minimap *minimap, int x, int y, int color)
// {
// 	char	*px;

// 	if (x >= 0 && x < minimap->width && y >= 0 && y < minimap->height)
// 	{
// 		px = minimap->img.addr
// 			+ (y * minimap->img.size_line + x * (minimap->img.bpp / 8));
// 		*(unsigned int *)px = color;
// 	}
// }

void	put_minimap_pixel(t_minimap *minimap, int x, int y, int color)
{
	if (x >= 0 && x < minimap->width && y >= 0 && y < minimap->height)
		put_pixel(&minimap->img, x, y, color);
}

void	paint_tile(t_game *game, t_coord tile, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->minimap.scale)
	{
		j = 0;
		while (j < game->minimap.scale)
		{
			put_minimap_pixel(&game->minimap, tile.x + i, tile.y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap_player(t_game *game)
{
	t_coord		pos;
	int			i;
	int			j;
	int			color;

	color = 0xFF0000;
	pos.x = (int)(game->mapdata->player.pos.x * game->minimap.scale);
	pos.y = (int)(game->mapdata->player.pos.y * game->minimap.scale);
	i = -game->minimap.player_size;
	while (i <= game->minimap.player_size)
	{
		j = -game->minimap.player_size;
		while (j < game->minimap.player_size)
		{
			if (sqrt(i * i + j * j) <= game->minimap.player_size)
				put_minimap_pixel(&game->minimap, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int		x;
	int		y;
	int		color;
	t_coord	tile;

	y = 0;
	while (game->mapdata->map[y])
	{
		x = 0;
		while (game->mapdata->map[y][x])
		{
			tile.x = x * game->minimap.scale;
			tile.y = y * game->minimap.scale;
			if (game->mapdata->map[y][x] == '1')
				color = game->minimap.wall_color;
			else if (game->mapdata->map[y][x] == '0')
				color = game->minimap.empty_color;
			else
				color = 0x000000;
			paint_tile(game, tile, color);
			x++;
		}
		y++;
	}
}

void	render_minimap(t_game *game)
{
	draw_minimap(game);
	draw_minimap_player(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
		game->minimap.img.img, 10, 10);
}
