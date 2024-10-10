/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/10 18:33:25 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	**import_map(char **file)
{
	char	**map;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (file[i] && !check_map_line(file[i]))
		++i;
	j = i;
	while (file[j] && check_map_line(file[j]))
		++j;
	map = malloc((j - i + 1) * sizeof(char *));
	if (!map)
		ft_error("malloc failed");
	k = i;
	while (i < j)
	{
		map[i - k] = ft_strdup(file[i]);
		++i;
	}
	map[i - k] = NULL;
	return (map);
}

/*
	Parse the map file and store it in the game structure
*/
void	parse_map(t_game *game, char **file)
{
	char		**map;

	game->mapdata = malloc(sizeof(t_mapdata));
	map = NULL;
	map = import_map(file);
	game->mapdata->map = map;
}
