/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/09 18:39:07 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*parsing(t_game *game, char *lvlPath)
{
	int	i;
	parse_map(game, lvlPath);

	i = 0;
	while (game->mapdata->map[i])
	{
		ft_printf("%s", game->mapdata->map[i]);
		i++;
	}
	ft_printf("\n");
	return (game);
}