/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:44:03 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/21 15:46:54 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../include/cub3d.h"
# include <fcntl.h>

# define WHITESPACE " \n\t"
# define MAP_CHARS "01NSEW"
# define SPAWN_CHARS "NSEW"
# define COLOR_CHARS "0123456789,"

# ifndef FILE_SUFFIX
#  define FILE_SUFFIX ".cub"
# endif

char	**file_parser(char *file_path);
void	parse_map(t_game *game, char **file, char *path);
void	parse_textures(t_game *game);
bool	check_map_line(char *line);
void	clean_map(char **map);
bool	parse_colors(t_game *game, char **file_content);

#endif
