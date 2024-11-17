/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:09:24 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/17 11:09:14 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	init_minimap(t_game *game)
{
	t_minimap	*minimap;

	minimap = &game->minimap;
	minimap->width = game->width / 4;
	minimap->height = game->height / 4;
	minimap->img.img = mlx_new_image(game->mlx.ptr,
			minimap->width, minimap->height);
	minimap->img.addr = mlx_get_data_addr(minimap->img.img, &minimap->img.bpp,
			&minimap->img.size_line, &minimap->img.endian);
	if (!minimap->img.img || !minimap->img.addr)
		return (false);
	return (true);
}

void	init_bonus(t_game *game)
{
	game->bonus = false;
	game->minimap.img.img = NULL;
	game->minimap.width = 0;
	game->minimap.height = 0;
	if (BONUS_FLAG)
	{
		game->bonus = true;
		if (!init_minimap(game))
		{
			cleanup_game(game);
			ft_putendl_fd("Could not initialize minimap", 2);
			exit(EXIT_FAILURE);
		}
	}
}
