/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/21 15:47:32 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*parsing(t_game *game, char *lvl_path)
{
	int		i;
	char	**file_content;

	file_content = file_parser(lvl_path);
	i = 0;
	while (file_content[i])
		printf("%s\n", file_content[i++]);
	printf("\n");
	parse_map(game, file_content, lvl_path);
	if (!game->mapdata->map)
		ft_error("No map found");
	parse_textures(game);
	if (!parse_colors(game, file_content))
		ft_error("Invalid color format");
	ft_free_split(file_content);
	game->mapdata->tmp = NULL;
	return (game);
}
