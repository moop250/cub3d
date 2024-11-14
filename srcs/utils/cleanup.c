/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:32:06 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/14 16:31:43 by hlibine          ###   ########.fr       */
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
	if (game->mlx.img_ptr)
		mlx_destroy_image(game->mlx.ptr, game->mlx.img_ptr);
	if (game->mlx.tmp_img)
		mlx_destroy_image(game->mlx.ptr, game->mlx.tmp_img);
	if (game->mlx.win_ptr)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win_ptr);
	if (game->mlx.ptr)
	{
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
	return (NULL);
}

void	*cleanup_game(t_game *game)
{
	int	i;

	i = 0;
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
		while (i < NUM_TEXTURES)
		{
			if (game->tex_pixels[i])
				free(game->tex_pixels[i++]);
		}
		free(game);
	}
	return (NULL);
}
