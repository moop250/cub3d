/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:44:03 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/10 18:29:22 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../include/cub3d.h"
# include <fcntl.h>

# ifndef FILE_SUFFIX
#  define FILE_SUFFIX ".cub"
# endif

char	**file_parser(t_game *game, char *file_path);
void	parse_map(t_game *game, char **file);
void	parse_textures(t_game *game);
bool	check_map_line(char *line);

#endif
