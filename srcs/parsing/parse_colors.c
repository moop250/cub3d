/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:09:16 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/25 17:09:33 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h>

static void	check_colors(t_game *game)
{
	int	i;

	i = -1;
	while (++i <= 2)
		if (game->mapdata->colors[0][i] < 0
			|| game->mapdata->colors[0][i] > 255
			|| game->mapdata->colors[1][i] < 0
			|| game->mapdata->colors[1][i] > 255)
			ft_error("Invalid color format");
	printf("\nColors validated\n");
}

static bool	treat_split(t_game *game, char **split, const char mode)
{
	t_indexes	ints;
	char		*tmp;

	ints.i = -1;
	while (split[++ints.i])
	{
		ints.j = -1;
		tmp = ft_strtrim(split[ints.i], " ");
		if (!tmp)
			return (printf("Error: malloc failed\n"), false);
		ft_free(split[ints.i]);
		split[ints.i] = tmp;
		while (split[ints.i][++ints.j])
			if (!ft_strchr("0123456789", split[ints.i][ints.j]))
				return (printf("Error: Obstruction in numbers\n"), false);
	}
	if (ints.i != 3)
		return (printf("Invalid floor or ceiling color format\n"), false);
	if (mode == 'F')
		while (--ints.i >= 0)
			game->mapdata->colors[0][ints.i] = ft_atoi(split[ints.i]);
	else
		while (--ints.i >= 0)
			game->mapdata->colors[1][ints.i] = ft_atoi(split[ints.i]);
	return (true);
}

// Set the color of the floor and ceiling
static bool	set_color(t_game *game, char *line, const char mode, int	*c)
{
	int		i;
	char	*tmp;
	char	**split;

	i = 0;
	printf("Color set loaded: %s\n", line);
	while (line[++i])
	{
		if (!ft_strchr(COLOR_CHARS, line[i]))
			return (ft_free(line), false);
	}
	tmp = ft_strtrim(line, "FC ");
	ft_free(line);
	if (!tmp)
		return (ft_free_bool(tmp, "trim failed", false));
	split = ft_split(tmp, ',');
	ft_free(tmp);
	if (!split)
		return (ft_free_bool(tmp, "split failed", false));
	if (!treat_split(game, split, mode))
		return (ft_free_split(split), false);
	ft_free_split(split);
	++*c;
	return (true);
}

static char	*prepare_colors(const char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (!tmp)
		ft_error("malloc failed");
	return (tmp);
}

bool	parse_colors(t_game *game, char **file_content)
{
	int		ints[3];
	char	*tmp;

	ints[0] = -1;
	ints[1] = 0;
	ints[2] = 0;
	while (file_content[++ints[0]])
	{
		tmp = prepare_colors(file_content[ints[0]]);
		if (tmp[0] == 'F' && tmp[1] == ' ')
		{
			if (!set_color(game, tmp, 'F', &ints[1]))
				return (false);
		}
		else if (tmp[0] == 'C' && tmp[1] == ' ')
		{
			if (!set_color(game, tmp, 'C', &ints[2]))
				return (false);
		}
		else
			ft_free(tmp);
	}
	if (ints[1] != 1 || ints[2] != 1)
		return (false);
	return (check_colors(game), true);
}
