/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:09 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/10 18:34:26 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*parsing(t_game *game, char *lvl_path)
{
	int		i;
	char	**file_content;

	file_content = file_parser(game, lvl_path);
	i = 0;
	while (file_content[i])
		ft_printf("%s", file_content[i++]);
	ft_printf("\n");
	ft_printf("Map \"%s\" loaded\n", lvl_path);
	i = 0;
	while (game->mapdata->map[i])
		ft_printf("%s", game->mapdata->map[i++]);
	ft_printf("\n");
	ft_free_split(file_content);
	return (game);
}
