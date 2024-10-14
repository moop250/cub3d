/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/14 21:40:13 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*parsing(t_game *game, char *lvl_path)
{
	int		i;
	char	**file_content;

	file_content = file_parser(lvl_path);
	i = 0;
	parse_map(game, file_content);
	while (file_content[i])
		printf("%s\n", file_content[i++]);
	printf("\n");
	printf("Map \"%s\" loaded\n", lvl_path);
	i = 0;
	while (game->mapdata->map[i])
		printf("%s\n", game->mapdata->map[i++]);
	ft_free_split(file_content);
	return (game);
}
