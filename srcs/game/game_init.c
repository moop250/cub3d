/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:45:54 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/04 16:04:17 by dcaro-ro         ###   ########.fr       */
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

static bool	game_mlx_init(t_game *game)
{
	game->mlx.win_ptr = mlx_new_window(game->mlx.ptr,
			game->width, game->height, "cub3D");
	if (!game->mlx.win_ptr)
	{
		cleanup_game(game);
		return (ft_free_bool(NULL, "Failed to create window", false));
	}
	game->mlx.img_ptr = mlx_new_image(game->mlx.ptr, game->width, game->height);
	if (!game->mlx.img_ptr)
	{
		cleanup_game(game);
		return (ft_free_bool(NULL, "Failed to create image", false));
	}
	game->mlx.addr = mlx_get_data_addr(game->mlx.img_ptr, &game->mlx.bpp,
			&game->mlx.size_line, &game->mlx.endian);
	if (!game->mlx.addr)
	{
		cleanup_game(game);
		return (ft_free_bool(NULL, "Failed to get image address", false));
	}
	return (true);
}

void	init_texture_data(t_game *game)
{
	game->textures->north.addr = mlx_get_data_addr(game->textures->north.img,
			&game->textures->north.bpp, &game->textures->north.size_line,
			&game->textures->north.endian);
	game->textures->south.addr = mlx_get_data_addr(game->textures->south.img,
			&game->textures->south.bpp, &game->textures->south.size_line,
			&game->textures->south.endian);
	game->textures->east.addr = mlx_get_data_addr(game->textures->east.img,
			&game->textures->east.bpp, &game->textures->east.size_line,
			&game->textures->east.endian);
	game->textures->west.addr = mlx_get_data_addr(game->textures->west.img,
			&game->textures->west.bpp, &game->textures->west.size_line,
			&game->textures->west.endian);
}

// Initialize game structure
bool	game_init(t_game *game)
{
	game->width = WIN_WIDTH;
	game->height = WIN_HEIGHT;
	if (!game_mlx_init(game))
	{
		cleanup_game(game);
		return (ft_free_bool(NULL, "Failed to initialize mlx", false));
	}
	if (!init_pixels(game))
	{
		cleanup_game(game);
		return (ft_free_bool(NULL, "Failed to initialize pixels", false));
	}
	init_texture_data(game);
	return (true);
}
