/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:45:54 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/21 00:33:00 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	*free_pixels(int **pixels, unsigned int rows)
{
	unsigned int	i;

	i = 0;
	while (i < rows)
	{
		free(pixels[i]);
		i++;
	}
	free(pixels);
	return (NULL);
}

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
t_game	*game_init(t_mapdata *mapdata, t_textures *textures)
{
	t_game	*game;
	int		i;

	game = ft_safe_malloc(sizeof(t_game), GAME_ERR_MALLOC);
	game->mapdata = mapdata;
	game->textures = textures;
	game->width = WIN_WIDTH;
	game->height = WIN_HEIGHT;
	game->textures = textures;
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
	{
		// free textures
		perror("Failed to initialize MiniLibX");
		return (ft_free(game));
	}
	game->mlx.mlx_window = mlx_new_window(game->mlx.mlx,
			game->width, game->height, "cub3D");
	if (!game->mlx.mlx_window)
	{
		// free textures
		perror("Failed to create window");
		return (ft_free(game));
	}
	if (!init_pixels(game))
	{
		// free textures
		return (ft_free(game));
	}
}