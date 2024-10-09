/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/09 14:56:03 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"		

static int	baseMapCheck(const char *lvl_path)
{
	size_t	file_len;
	size_t	suffix_len;
	int		fd;

	fd = 0;
	file_len = ft_strlen(lvl_path);
	suffix_len = ft_strlen(FILE_SUFFIX);
	if (file_len < suffix_len || ft_strncmp(lvl_path + (file_len - suffix_len), FILE_SUFFIX, suffix_len))
		return (ft_printf("Error: Invalid file extension\n"), fd);
	else if (fd = open(lvl_path, O_RDONLY), fd < 0)
		ft_printf("Error: Could not open map file\n");
	return (fd);
}

void	parse_map(t_game *game, const char *lvl_path)
{
	int			fd;	

	if (fd = baseMapCheck(lvl_path), fd < 0)
		exit(1);
	game->mapdata = malloc(sizeof(t_mapdata));
	close(fd);
}