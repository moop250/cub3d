/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/10 00:28:05 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*parsing(t_game *game, char *lvl_path)
{
	int	i;

	parse_map(game, lvl_path);
	i = 0;
	while (game->mapdata->map[i])
	{
		ft_printf("%s", game->mapdata->map[i]);
		i++;
	}
	ft_printf("\n");
	return (game);
}
