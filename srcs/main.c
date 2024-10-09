/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:38:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/09 20:16:33 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	freeall(t_game *game)
{
	ft_free_split(game->mapdata->map);
	ft_safe_free(1, game->mapdata);
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
	if (game = malloc(sizeof(t_game)), !game)
		exit(1);
	ft_printf("hello world\n");
	parsing(game, av[1]);
	freeall(game);
	return (0);
}
