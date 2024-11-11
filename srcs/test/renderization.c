/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:51:09 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/29 09:52:06 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	put_pixel(t_game *game, int x, int y, int color)
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

void	render_scene(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	if (!game || !game->pixels)
	{
		ft_putendl_fd("Game or pixels array is not initialized", 2);
		return ;
	}
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			color = game->pixels[y][x];
			put_pixel(game, x, y, color);
			x++;
		}
		y++;
	}
}


// static void	put_pixel(t_game *game, int x, int y, int color)
// {
// 	char	*px;
// 	int		size_line;

// 	size_line = game->mlx.size_line;
// 	if (x >= 0 && x < game->width && y >= 0 && y < game->height)
// 	{
// 		px = game->mlx.addr + (y * size_line + x * (game->mlx.bpp / 8));
// 		*(unsigned int *)px = color;
// 	}
// }

// static void	render_dirty_area(t_game *game, t_rect dirty_rect)
// {
// 	int		x;
// 	int		y;
// 	int		color;

// 	y = dirty_rect.y;
// 	while (y < dirty_rect.y + dirty_rect.height)
// 	{
// 		x = dirty_rect.x;
// 		while (x < dirty_rect.x + dirty_rect.width)
// 		{
// 			if (x >= 0 && x < game->width && y >= 0 && y < game->height)
// 			{
// 				color = game->pixels[y][x];
// 				put_pixel(game, x, y, color);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// static void	mark_dirty(t_dirty_rect *dirty, t_rect rect)
// {
// 	if (dirty->count < MAX_DIRTY_RECTS)
// 	{
// 		dirty->rects[dirty->count] = rect;
// 		dirty->count++;
// 	}
// }

// void	update_player_position(t_game *game, int new_x, int new_y)
// {
// 	t_rect		old_rect;
// 	t_rect		new_rect;
// 	t_player	*player;

// 	player = &game->mapdata->player;

// }

// void	render_scene(t_game *game)
// {
// 	int		i;
// 	t_rect	dirty_rect;

// 	i = 0;
// 	while (i < game->dirty.count)
// 	{
// 		dirty_rect = game->dirty.rects[i];
// 		render_dirty_area(game, dirty_rect);
// 		i++;
// 	}
// 	game->dirty.count = 0;
// }
