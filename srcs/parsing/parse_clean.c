/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:52:35 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/14 21:23:02 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	clean_lines(char **map)
{
	int	i;
	int	len;
	int	next_len;
	int	j;
	int	k;

	i = 1;
	len = -1;
	while (map[i])
	{
		if (!map[i + 1])
			break;
		if (len == -1)
			len = ft_strlen(map[i]);
		else
			len = next_len;
		next_len = ft_strlen(map[++i]);
		if (len == next_len)
			continue ;
		
		j = len;
		k = next_len;
		if (len > next_len)
		{
			map[i] = ft_safe_memresize(map[i], next_len, len, "failed realloc");
			while (k < j)
				map[i][k++] = '\0';
		}
		else
		{
			map[i - 1] = ft_safe_memresize(map[i - 1], len, next_len, "failed realloc");
			while (j < k)
				map[i - 1][j++] = '\0';
		}
	}
}

void	clean_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(map[1]);
	map[j] = malloc(i * sizeof(char));
	while (--i >= 0)
		map[j][i] = '\0';
	while (map[j])
		++j;
	i = ft_strlen(map[j - 1]);
	map[j] = malloc(i * sizeof(char));
	while (--i >= 0)
		map[j][i] = '\0';
	clean_lines(map);
}