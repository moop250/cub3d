/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:16:59 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/03 13:19:49 by dcaro-ro         ###   ########.fr       */
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

static void	render_frame(t_game *game)
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
