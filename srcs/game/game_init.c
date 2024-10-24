/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:45:54 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/24 10:42:10 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Initialize the screen buffer
static bool	init_pixels(t_game *game)
{
	int	i;

	game->pixels = malloc(sizeof(int *) * game->height);
	if (!game->pixels)
	{
		cleanup_game(game);
		ft_putstr_fd(GAME_PIX_ERR, 2);
		return (false);
	}
	i = 0;
	while (i < game->height)
	{
		game->pixels[i] = malloc(sizeof(int) * game->width);
		if (!game->pixels[i])
		{
			free_pixels(game->pixels, i);
			cleanup_game(game);
			ft_putstr_fd(GAME_PIX_ERR, 2);
			return (false);
		}
		i++;
	}
	return (true);
}

// Initialize game structure
bool	game_init(t_game *game)
{
	game->width = WIN_WIDTH;
	game->height = WIN_HEIGHT;
	game->mlx.window = mlx_new_window(game->mlx.ptr,
			game->width, game->height, "cub3D");
	if (!game->mlx.window)
	{
		cleanup_game(game);
		return (ft_free_bool(NULL, "Failed to create window", false));
	}
	if (!init_pixels(game))
	{
		cleanup_game(game);
		return (false);
	}
	return (true);
}
