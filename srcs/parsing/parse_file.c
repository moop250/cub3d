/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:06:00 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/10 18:29:43 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	Check if the file extension is correct and if the file can be opened
	Returns the file descriptor if everything is correct, otherwise returns -1
*/
static int	base_file_check(const char *file_path)
{
	size_t	file_len;	
	size_t	suffix_len;
	int		fd;

	fd = 0;
	file_len = ft_strlen(file_path);
	suffix_len = ft_strlen(FILE_SUFFIX);
	if (file_len <= suffix_len || ft_strncmp(file_path
			+ (file_len - suffix_len), FILE_SUFFIX, suffix_len))
		ft_error("Invalid file extension");
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_error("Could not open map file");
	return (fd);
}

bool	check_map_line(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (!tmp)
		ft_error("malloc failed");
	if (tmp[0] != '1' && tmp[ft_strlen(tmp) - 1] != '1')
	{
		ft_free(tmp);
		return (false);
	}
	ft_free(tmp);
	return (true);
}

static bool	file_check(char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i][0] == 'N' && file[i][1] == 'O' && file[i][2] == ' ')
			++i;
		else if (file[i][0] == 'S' && file[i][1] == 'O' && file[i][2] == ' ')
			++i;
		else if (file[i][0] == 'W' && file[i][1] == 'E' && file[i][2] == ' ')
			++i;
		else if (file[i][0] == 'E' && file[i][1] == 'A' && file[i][2] == ' ')
			++i;
		else if (file[i][0] == 'F' && file[i][1] == ' ')
			++i;
		else if (file[i][0] == 'C' && file[i][1] == ' ')
			++i;
		else if (check_map_line(file[i]))
			++i;
		else
			return (false);
	}
	return (true);
}

static char	**file_parser_loop(int fd, char *line, char **file, int i)
{
	char	*tmp;

	while (line)
	{
		tmp = ft_strtrim(line, " ");
		if (!tmp)
			ft_error("malloc failed");
		else if (!tmp[0] || tmp[0] == '\n')
		{
			ft_safe_free(2, tmp, line);
			line = get_next_line(fd);
			continue ;
		}
		ft_safe_free(1, tmp);
		file = ft_memresize(file, (i + 1) * sizeof(char *),
				(i + 2) * sizeof(char *));
		if (!file)
			ft_error("realloc failed");
		file[i++] = line;
		line = get_next_line(fd);
	}
	file[i] = NULL;
	close(fd);
	return (file);
}

char	**file_parser(t_game *game, char *file_path)
{
	int		fd;
	char	**file;
	char	*line;
	int		i;

	i = 0;
	fd = base_file_check(file_path);
	file = NULL;
	line = get_next_line(fd);
	file = file_parser_loop(fd, line, file, i);
	if (!file_check(file))
	{
		ft_free_split(file);
		ft_error("Invalid file content");
	}
	parse_map(game, file);
	return (file);
}
