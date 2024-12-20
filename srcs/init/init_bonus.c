/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:09:24 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/21 15:03:00 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	init_minimap(t_game *game)
{
	game->minimap.scale = 5;
	game->minimap.player_size = 3;
	game->minimap.player_color = PLAYER_COLOR;
	game->minimap.wall_color = WALL_COLOR;
	game->minimap.empty_color = EMPTY_COLOR;
	game->minimap.width = game->mapdata->width * game->minimap.scale + 10;
	game->minimap.height = game->mapdata->height * game->minimap.scale + 10;
	game->minimap.img.img = mlx_new_image(game->mlx.ptr,
			game->minimap.width, game->minimap.height);
	game->minimap.img.addr = mlx_get_data_addr(game->minimap.img.img,
			&game->minimap.img.bpp, &game->minimap.img.size_line,
			&game->minimap.img.endian);
	if (!game->minimap.img.img || !game->minimap.img.addr)
	{
		ft_putendl_fd("Could not create minimap image", 2);
		return (false);
	}
	return (true);
}

void	init_bonus(t_game *game)
{
	game->bonus = BONUS_FLAG;
	game->minimap.img.img = NULL;
	game->minimap.width = 0;
	game->minimap.height = 0;
	if (game->bonus == 1)
	{
		if (!init_minimap(game))
			exit(EXIT_FAILURE);
	}
}
