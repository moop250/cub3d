/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/11 18:58:41 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdbool.h>
#include <stdio.h>

// Reapproach
static bool	check_walls(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		printf(">>>>%s%%\n", map[i]);
		j = -1;
		while (map[i][++j])
		{
			while (ft_strchr(WHITESPACE, map[i][j]))
				++j;
			if (map[i][j] == '1')
				continue ;
/* 			if (!ft_strchr(MAP_CHARS, map[i][j]))
				return (false);
			if (map[i][j] && i > 0)
				if (!ft_strchr(MAP_CHARS, map[i - 1][j]))
					return (false);
			if (map[i][j] && map[i + 1])
				if (!ft_strchr(MAP_CHARS, map[i + 1][j]))
					return (false);
			if (map[i][j] && j > 0)
				if (!ft_strchr(MAP_CHARS, map[i][j - 1]))
					return (false);
			if (map[i][j] && map[i][j + 1])
				if (!ft_strchr(MAP_CHARS, map[i][j + 1]))
					return (false); */
		}
	}
	return (true);
}

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
	while (file[j])
		++j;
	map = malloc((j - i + 1) * sizeof(char *));
	if (!map)
		ft_error("malloc failed");
	k = i;
	while (i < j)
	{
		map[i - k] = ft_strdup(file[i]);
		if (!map[i - k])
			ft_error("malloc failed");
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
	map = import_map(file);
	if (check_walls(map) == false)
		ft_error("Invalid map elements");
	game->mapdata->map = map;
}
