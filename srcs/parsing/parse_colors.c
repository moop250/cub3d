/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:09:16 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/25 16:19:33 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

static void	treat_split(t_game *game, char **split, char mode)
{
	int		i;

	i = 0;
	while (split[i])
		++i;
	if (i != 3)
	{
		ft_free_split(split);
		if (mode == 'F')
			ft_error("Invalid floor color format");
		else
			ft_error("Invalid ceiling color format");
	}
	i = -1;
	if (mode == 'F')
		while (++i <= 2)
			game->mapdata->colors[0][i] = ft_atoi(split[i]);
	else
		while (++i <= 2)
			game->mapdata->colors[1][i] = ft_atoi(split[i]);
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
	if (!split)
		return (ft_free_bool(tmp, "split failed", false));
	treat_split(game, split, mode);
	ft_free_split(split);
	++*c;
	return (ft_free(tmp), true);
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
