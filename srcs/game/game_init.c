/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:45:54 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/24 10:03:03 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Initialize the screen buffer
static bool	init_pixels(t_game *game)
{
	unsigned int	i;

	game->pixels = ft_safe_malloc(sizeof(int *) * game->height, GAME_PIX_ERR);
	i = 0;
	while (i < game->height)
	{
		game->pixels[i] = malloc(sizeof(int) * game->width);
		if (!game->pixels[i])
		{
			free_pixels(game->pixels, i);
			perror(GAME_PIX_ERR);
			return (false);
		}
		i++;
	}
	return (true);
}

// Initialize game structure
t_game	*game_init(t_game *game, t_mapdata *mapdata, t_textures *textures)
{
	game->mapdata = mapdata;
	game->width = WIN_WIDTH;
	game->height = WIN_HEIGHT;
	game->mlx.window = mlx_new_window(game->mlx.ptr,
			game->width, game->height, "cub3D");
	if (!game->mlx.window)
	{
		freeall();
		return (ft_free_msg(NULL, "Failed to create window"));
	}
	if (!init_pixels(&game))
	{
		freeall();
		return (NULL);
	}
	return (game);
}
