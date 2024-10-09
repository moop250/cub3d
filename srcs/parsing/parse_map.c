/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:45:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/10 00:45:12 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	Check if the file extension is correct and if the file can be opened
	Returns the file descriptor if everything is correct, otherwise returns -1
*/
static int	base_map_check(const char *map_path)
{
	size_t	file_len;	
	size_t	suffix_len;
	int		fd;

	fd = 0;
	file_len = ft_strlen(map_path);
	suffix_len = ft_strlen(FILE_SUFFIX);
	if (file_len < suffix_len || ft_strncmp(map_path
			+ (file_len - suffix_len), FILE_SUFFIX, suffix_len))
		return (ft_printf("Error: Invalid file extension\n"), fd);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error: Could not open map file\n");
	return (fd);
}

static char	**parser_loop(int fd, char *line, char **map, int i)
{
	char	*tmp;

	while (line)
	{
		tmp = ft_strtrim(line, " ");
		if (!tmp)
			ft_error("malloc failed");
		else if (tmp[0] != '1')
		{
			ft_safe_free(2, tmp, line);
			line = get_next_line(fd);
			continue ;
		}
		ft_safe_free(1, tmp);
		map = ft_memresize(map, i * sizeof(char *), (i + 1) * sizeof(char *));
		if (!map)
			ft_error("realloc failed");
		map[i++] = line;
		line = get_next_line(fd);
	}
	map = ft_memresize(map, i * sizeof(char *), (i + 1) * sizeof(char *));
	if (!map)
		ft_error("realloc failed");
	map[i] = NULL;
	return (map);
}

/*
	Parse the map file and store it in the game structure
*/
void	parse_map(t_game *game, const char *map_path)
{
	int			fd;
	int			i;
	char		*line;
	char		**map;

	i = 0;
	fd = base_map_check(map_path);
	if (fd < 0)
		exit(1);
	game->mapdata = malloc(sizeof(t_mapdata));
	map = NULL;
	line = get_next_line(fd);
	map = parser_loop(fd, line, map, i);
	close(fd);
	game->mapdata->map = map;
}
