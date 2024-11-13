/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:52:25 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 12:11:27 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//mlx.ptr was initialized during the parsing
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
	game->mlx.tmp_img = mlx_new_image(game->mlx.ptr, game->width, game->height);
	if (!game->mlx.img_ptr || !game->mlx.tmp_img)
	{
		cleanup_game(game);
		return (ft_free_bool(NULL, "Failed to create image", false));
	}
	game->mlx.addr = mlx_get_data_addr(game->mlx.img_ptr, &game->mlx.bpp,
			&game->mlx.size_line, &game->mlx.endian);
	game->mlx.tmp_addr = mlx_get_data_addr(game->mlx.tmp_img, &game->mlx.bpp,
			&game->mlx.size_line, &game->mlx.endian);
	if (!game->mlx.addr || !game->mlx.tmp_addr)
	{
		cleanup_game(game);
		return (ft_free_bool(NULL, "Failed to get image address", false));
	}
	return (true);
}

static bool	init_texture_data(t_game *game)
{
	int	i;

	game->tex[NO] = &game->textures->north;
	game->tex[SO] = &game->textures->south;
	game->tex[WE] = &game->textures->west;
	game->tex[EA] = &game->textures->east;
	i = 0;
	while (i < NUM_TEXTURES)
	{
		game->tex[i]->addr = mlx_get_data_addr(game->tex[i]->img,
				&game->tex[i]->bpp, &game->tex[i]->size_line,
				&game->tex[i]->endian);
		if (!game->tex[i]->addr)
		{
			cleanup_game(game);
			ft_putendl_fd("Failed to get texture address", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	allocate_tex_buf(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		game->tex_pixels[i] = malloc(sizeof(int) * TEX_SIZE * TEX_SIZE);
		if (!game->tex_pixels[i])
		{
			while (i > 0)
				free(game->tex_pixels[--i]);
			ft_putendl_fd("Failed to allocate texture buffer", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	load_texture_to_buffer(t_game *game)
{
	int		i;
	int		x;
	int		y;
	int		color;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			x = 0;
			while (x < TEX_WIDTH)
			{
				color = *(int *)(game->tex[i]->addr
						+ (y * game->tex[i]->size_line
							+ x * (game->tex[i]->bpp / 8)));
				game->tex_pixels[i][y * TEX_WIDTH + x] = color;
				x++;
			}
			y++;
		}
		i++;
	}
	//destroy_textures(game);
}

bool	game_init(t_game *game)
{
	game->width = WIN_WIDTH;
	game->height = WIN_HEIGHT;
	game->floor_color = get_color(game->mapdata->colors[0][0],
			game->mapdata->colors[0][1], game->mapdata->colors[0][2]);
	game->ceiling_color = get_color(game->mapdata->colors[1][0],
			game->mapdata->colors[1][1], game->mapdata->colors[1][2]);
	if (!game_mlx_init(game)
		|| !init_texture_data(game) || !allocate_tex_buf(game))
	{
		cleanup_game(game);
		return (false);
	}
	load_texture_to_buffer(game);
	return (true);
}
