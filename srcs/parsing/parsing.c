/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/18 13:04:54 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_map_dimensions(t_game *game)
{
	int	map_width;
	int	map_height;
	int	row_width;

	map_width = 0;
	map_height = 0;
	while (game->mapdata->map[map_height])
	{
		row_width = ft_strlen(game->mapdata->map[map_height]);
		if (row_width > map_width)
			map_width = row_width;
		map_height++;
	}
	game->mapdata->width = map_width;
	if (ft_strlen(game->mapdata->map[map_height - 1]) == 0)
		game->mapdata->height = map_height - 2;
	else
		game->mapdata->height = map_height - 1;
	printf("Map width: %d\n", game->mapdata->width); // debug
	printf("Map height: %d\n", game->mapdata->height); // debug
}

void	*parsing(t_game *game, char *lvl_path)
{
	char	**file_content;

	file_content = file_parser(lvl_path);
	parse_map(game, file_content, lvl_path);
	if (!game->mapdata->map)
		ft_error("No map found");
	parse_textures(game);
	if (!parse_colors(game, file_content))
		ft_error("Invalid color format");
	ft_free_split(file_content);
	game->mapdata->tmp = NULL;
	get_map_dimensions(game);
	return (game);
}
