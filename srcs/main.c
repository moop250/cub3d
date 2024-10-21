/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:38:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/21 13:21:51 by hlibine          ###   ########.fr       */
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
	return (game);
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
			ft_safe_free(1, game->textures);
		ft_safe_free(1, game->mapdata);
	}
	ft_safe_free(1, game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_printf("Error: Invalid number of arguments\n");
		exit(1);
	}
	game = get_game();
	game->mlx.mlx = mlx_init();
	parsing(game, av[1]);
	freeall();
	return (0);
}
