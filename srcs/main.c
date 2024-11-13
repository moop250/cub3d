/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:38:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/13 18:49:31 by hlibine          ###   ########.fr       */
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
	game->mlx.ptr = NULL;
	game->mlx.win_ptr = NULL;
	return (game);
}

void	freemlx(t_mlx mlx)
{
	if (mlx.ptr)
	{
		if (mlx.win_ptr)
			mlx_destroy_window(mlx.ptr, mlx.win_ptr);
		mlx_destroy_display(mlx.ptr);
		ft_free(mlx.ptr);
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
				mlx_destroy_image(game->mlx.ptr, game->textures->north.img);
			if (game->textures->south.img)
				mlx_destroy_image(game->mlx.ptr, game->textures->south.img);
			if (game->textures->west.img)
				mlx_destroy_image(game->mlx.ptr, game->textures->west.img);
			if (game->textures->east.img)
				mlx_destroy_image(game->mlx.ptr, game->textures->east.img);
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
		ft_putendl_fd("Usage: ./cub3d <map.cub>", 2);
		return (1);
	}
	game = get_game();
	game->mlx.ptr = mlx_init();
	parsing(game, av[1]);
	if (!game_init(game))
	{
		cleanup_game(game);
		return (1);
	}
	// ft_putstr_fd("Rendering game\n", 1);
	// game_play(game);
	mlx_hook(game->mlx.win_ptr, 2, 1L << 0, &handle_keypress, game);
	mlx_hook(game->mlx.win_ptr, 17, 0, &exit_game, game);
	mlx_loop_hook(game->mlx.ptr, &game_play, game);
	mlx_loop(game->mlx.ptr);
	cleanup_game(game);
	return (0);
}
