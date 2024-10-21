/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:09:16 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/21 18:38:20 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	check_colors(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 2)
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
		while (++i < 2)
			game->mapdata->colors[0][i] = ft_atoi(split[i]);
	else
		while (++i < 2)
			game->mapdata->colors[1][i] = ft_atoi(split[i]);
}

static bool	set_color(t_game *game, char *line, char mode)
{
	int		i;
	char	*tmp;
	char	**split;

	i = -1;
	tmp = ft_strtrim(line, "FC ");
	if (!tmp)
		ft_error("malloc failed");
	printf("Color set loaded: %s\n", tmp);
	while (tmp[++i])
	{
		if (!ft_strchr(COLOR_CHARS, tmp[i]))
		{
			ft_free(tmp);
			ft_error("Unauthorized character in color");
			return (false);
		}
	}
	split = ft_split(tmp, ',');
	if (!split)
		ft_error("malloc failed");
	ft_free(tmp);
	treat_split(game, split, mode);
	ft_free_split(split);
	return (true);
}

bool	parse_colors(t_game *game, char **file_content)
{
	int		i;
	int		counts[2];

	i = -1;
	counts[0] = 0;
	counts[1] = 0;
	while (file_content[++i])
	{
		if (file_content[i][0] == 'F' && file_content[i][1] == ' ')
		{
			if (!set_color(game, file_content[i], 'F'))
				return (false);
			++counts[0];
		}
		else if (file_content[i][0] == 'C' && file_content[i][1] == ' ')
		{
			if (!set_color(game, file_content[i], 'C'))
				return (false);
			++counts[1];
		}
	}
	if (counts[0] != 1 || counts[1] != 1)
		return (false);
	check_colors(game);
	return (true);
}
