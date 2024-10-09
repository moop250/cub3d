/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/09 17:34:43 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"		


/*
	Check if the file extension is correct and if the file can be opened
	Returns the file descriptor if everything is correct, otherwise returns -1
*/
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
	int			i;
	char		*line;
	char 		**map;
	char		*tmp;

	i = 0;
	if (fd = baseMapCheck(lvl_path), fd < 0)
		exit(1);
	game->mapdata = malloc(sizeof(t_mapdata));
	map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = NULL;
		if (tmp = ft_strtrim(line, " "), !tmp)
			ft_error("malloc failed");
		else if (tmp[0] != '1')
		{
			ft_safe_free(1, tmp, line);
			line = get_next_line(fd);
			continue;
		}
		ft_safe_free(1, tmp);
		if (map = ft_realloc(map, (i + 1) * sizeof(char *), i * sizeof(char *)), !map)
			ft_error("realloc failed");
		map[i++] = line;
		line = get_next_line(fd);
	}
	if (map = ft_realloc(map, (i + 1) * sizeof(char *), i * sizeof(char *)), !map)
		ft_error("malloc failed");
	map[i] = NULL;
	close(fd);
	game->mapdata->map = map;
}