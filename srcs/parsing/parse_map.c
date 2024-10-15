/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/15 13:57:05 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	check_directions(char up, char down, char left, char right)
{
	if (!ft_strchr(MAP_CHARS, up) || !up)
		return (false);
	if (!ft_strchr(MAP_CHARS, down) || !down)
		return (false);
	if (!ft_strchr(MAP_CHARS, left) || !left)
		return (false);
	if (!ft_strchr(MAP_CHARS, right) || !right)
		return (false);
	return (true);
}

// Reapproach
static int	check_walls(char **map)
{
	int	i;
	int	j;
	int	spawn_count;

	i = -1;
	spawn_count = 0;
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
				return (-1);
			if (!check_directions(map[i - 1][j], map[i + 1][j],
				map[i][j - 1], map[i][j + 1]))
				return (-1);
			if (ft_strchr(SPAWN_CHARS, map[i][j]))
				++spawn_count;
		}
	}
	return (spawn_count);
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

static void	status_print(char **map, char *path)
{
	int	i;

	printf("Map \"%s\" loaded\n", path);
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}

/*
	Parse the map file and store it in the game structure
*/
void	parse_map(t_game *game, char **file, char *path)
{
	char		**map;
	int			tmp;

	game->mapdata = ft_safe_malloc(sizeof(t_mapdata), "mapdata malloc failed");
	game->mapdata->map = NULL;
	map = import_map(file);
	clean_map(map);
	status_print(map, path);
	tmp = check_walls(map);
	if (tmp <= 0 || tmp > 1)
	{
		ft_free_split(map);
		ft_free_split(file);
		if (tmp == 0)
			ft_error("Invalid map: no spawn point");
		else if (tmp > 1)
			ft_error("Invalid map: multiple spawn points");
		else
			ft_error("Invalid map");
	}
	game->mapdata->map = map;
	printf("Map \"%s\" verrified\n\n", path);
}
