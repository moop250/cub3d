/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/23 18:24:41 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	if (i == j)
		return (NULL);
	map = ft_safe_malloc((j - i + 3) * sizeof(char *), "malloc failed");
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
	game->mapdata->tmp = file;
	game->mapdata->map = NULL;
	map = import_map(game->mapdata->tmp);
	if (!map)
		return ;
	game->mapdata->map = map;
	clean_map(map);
	status_print(map, path);
	tmp = check_walls(map, &game->mapdata->player);
	if (tmp <= 0 || tmp > 1)
	{
		if (tmp == 0)
			ft_error("Invalid map: no spawn point");
		else if (tmp > 1)
			ft_error("Invalid map: multiple spawn points");
		else
			ft_error("Invalid map");
	}
	printf("Map \"%s\" verified\n\n", path);
}
