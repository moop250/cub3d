/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:35:38 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/09 16:37:48 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	check_directions(char up, char down, char left, char right)
{
	if (!ft_strchr(MAP_CHARS, up) || !up)
		return (false);
	if (!ft_strchr(MAP_CHARS, down) || !down)
		return (false);
	if (!ft_strchr(MAP_CHARS, left) || !left)
		return (false);
	if (!ft_strchr(MAP_CHARS, right) || !right)
		return (false);
	return (true);
}

static int	is_valid_cell(char c, char **map, int i, int j)
{
	if (c == '1')
		return (1);
	if (!ft_strchr(MAP_CHARS, c) || !c)
		return (-1);
	if (!check_directions(map[i - 1][j], map[i + 1][j],
		map[i][j - 1], map[i][j + 1]))
		return (-1);
	return (1);
}

static void	handle_spawn(char c, t_player *player, int x, int y)
{
	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	if (c == 'N')
	{
		player->angle = HALF_PI;
		player->plane = (t_vector){0.66, 0};
	}
	else if (c == 'S')
	{
		player->angle = 3 * HALF_PI;
		player->plane = (t_vector){-0.66, 0};
	}
	else if (c == 'E')
	{
		player->angle = 2 * PI;
		player->plane = (t_vector){0, -0.66};
	}
	else if (c == 'W')
	{
		player->angle = PI;
		player->plane = (t_vector){0, 0.66};
	}
	player->dir.x = cos(player->angle);
	player->dir.y = sin(player->angle);
}

static int	skip_whitespace(char **map, int *i, int *j)
{
	while (map[*i][*j] == ' ' || map[*i][*j] == '\t')
		++(*j);
	return (*j);
}

// ind.k == spawn_count
int	check_walls(char **map, t_player *player)
{
	t_indexes	ind;

	ind.i = -1;
	ind.k = 0;
	while (map[++ind.i])
	{
		ind.j = 0;
		while (map[ind.i][ind.j++])
		{
			ind.j = skip_whitespace(map, &ind.i, &ind.j);
			if (map[ind.i][ind.j] == '\0')
				continue ;
			if (is_valid_cell(map[ind.i][ind.j], map, ind.i, ind.j) == -1)
				return (-1);
			if (ft_strchr(SPAWN_CHARS, map[ind.i][ind.j]))
			{
				if (ind.k > 0)
					return (ind.k);
				handle_spawn(map[ind.i][ind.j], player, ind.j, ind.i);
				map[ind.i][ind.j] = '0';
				++ind.k;
			}
		}
	}
	return (ind.k);
}
