/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/14 22:39:20 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Reapproach
static bool	check_walls(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			while (ft_strchr(WHITESPACE, map[i][j]))
				++j;
			if (map[i][j] == '1')
				continue ;
			if (!ft_strchr(MAP_CHARS, map[i][j]) || !map[i][j])
				return (false);
			if (!ft_strchr(MAP_CHARS, map[i - 1][j]) || !map[i - 1][j])
				return (false);
			if (!ft_strchr(MAP_CHARS, map[i + 1][j]) || !map[i + 1][j])
				return (false);
			if (!ft_strchr(MAP_CHARS, map[i][j - 1]) || !map[i][j - 1])
				return (false);
			if (!ft_strchr(MAP_CHARS, map[i][j + 1]) || !map[i][j + 1])
				return (false);
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
	map = malloc((j - i + 3) * sizeof(char *));
	if (!map)
		ft_error("malloc failed");
	k = 1;
	while (i < j)
	{
		map[k++] = ft_strjoin(" ", file[i]);
		if (!map[k - 1])
			ft_error("malloc failed");
		++i;
	}
	map[k] = NULL;
	map[k + 1] = NULL;
	return (map);
}

/*
	Parse the map file and store it in the game structure
*/
void	parse_map(t_game *game, char **file)
{
	char		**map;

	game->mapdata = malloc(sizeof(t_mapdata));
	game->mapdata->map = NULL;
	map = import_map(file);
	clean_map(map);
	if (check_walls(map) == false)
	{
		ft_free_split(map);
		ft_free_split(file);
		ft_error("Invalid map");
	}
	game->mapdata->map = map;
}
