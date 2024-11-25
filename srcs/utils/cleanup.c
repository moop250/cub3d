/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:32:06 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/25 15:44:36 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	*destroy_textures(t_game *game)
{
	if (game->textures)
	{
		if (game->textures->north.img)
		{
			mlx_destroy_image(game->mlx.ptr, game->textures->north.img);
			game->textures->north.img = NULL;
		}
		if (game->textures->south.img)
		{
			mlx_destroy_image(game->mlx.ptr, game->textures->south.img);
			game->textures->south.img = NULL;
		}
		if (game->textures->west.img)
		{
			mlx_destroy_image(game->mlx.ptr, game->textures->west.img);
			game->textures->west.img = NULL;
		}
		if (game->textures->east.img)
		{
			mlx_destroy_image(game->mlx.ptr, game->textures->east.img);
			game->textures->east.img = NULL;
		}
		free(game->textures);
	}
	return (NULL);
}

void	*mlx_cleanup(t_game *game)
{
	mlx_do_key_autorepeaton(game->mlx.ptr);
	if (game->mlx.img.img)
		mlx_destroy_image(game->mlx.ptr, game->mlx.img.img);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win_ptr);
	if (BONUS_FLAG)
	{
		if (game->minimap.img.img)
			mlx_destroy_image(game->mlx.ptr, game->minimap.img.img);
		game->minimap.img.img = NULL;
	}
	if (game->mlx.ptr)
	{
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
	return (NULL);
}

void	*cleanup_game(t_game *game)
{
	if (game)
	{
		if (game->mapdata)
		{
			if (game->mapdata->map)
				ft_free_split(game->mapdata->map);
			if (game->mapdata->tmp)
				ft_free_split(game->mapdata->tmp);
			free(game->mapdata);
		}
		if (game->textures)
			destroy_textures(game);
		mlx_cleanup(game);
		if (game->tex_pixels[NO])
			ft_free(game->tex_pixels[NO]);
		if (game->tex_pixels[SO])
			ft_free(game->tex_pixels[SO]);
		if (game->tex_pixels[WE])
			ft_free(game->tex_pixels[WE]);
		if (game->tex_pixels[EA])
			ft_free(game->tex_pixels[EA]);
		free(game);
	}
	return (NULL);
}

bool	bcleanup_game(t_game *game, char *msg, bool flag)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	cleanup_game(game);
	return (flag);
}
