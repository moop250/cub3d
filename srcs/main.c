/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:38:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/21 18:43:03 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_game	*get_game(void)
{
	static t_game	*game;

	if (game)
		return (game);
	game = malloc(sizeof(t_game));
	if (!game)
		exit(1);
	game->mapdata = NULL;
	game->textures = NULL;
	game->mlx.mlx = NULL;
	game->mlx.mlx_window = NULL;
	return (game);
}

static void	freemlx(t_mlx mlx)
{
	if (mlx.mlx)
	{
		if (mlx.mlx_window)
			mlx_destroy_window(mlx.mlx, mlx.mlx_window);
		mlx_destroy_display(mlx.mlx);
		ft_free(mlx.mlx);
	}
}

void	freeall(void)
{
	t_game	*game;

	game = get_game();
	if (game->mapdata)
	{
		if (game->mapdata->map)
			ft_free_split(game->mapdata->map);
		if (game->mapdata->tmp)
			ft_free_split(game->mapdata->tmp);
		if (game->textures)
		{
			if (game->textures->north.img)
				mlx_destroy_image(game->mlx.mlx, game->textures->north.img);
			if (game->textures->south.img)
				mlx_destroy_image(game->mlx.mlx, game->textures->south.img);
			if (game->textures->west.img)
				mlx_destroy_image(game->mlx.mlx, game->textures->west.img);
			if (game->textures->east.img)
				mlx_destroy_image(game->mlx.mlx, game->textures->east.img);
			ft_safe_free(1, game->textures);
		}
		ft_safe_free(1, game->mapdata);
	}
	freemlx(game->mlx);
	ft_safe_free(1, game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3d <map.cub>\n", 2);
		return (1);
	}
	game = get_game();
	game->mlx.mlx = mlx_init();
	parsing(game, av[1]);
	freeall();
	return (0);
}
