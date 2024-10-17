/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:52:14 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/16 16:29:49 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	set_textures(t_game *game, char **paths)
{
	t_textures	*tex;

	game->textures = ft_safe_malloc(sizeof(t_textures), "malloc failed");
	tex = game->textures;
	tex->north->img = mlx_xpm_file_to_image(game->mlx.mlx, paths[0], &tex->north->width, &tex->north->hight);
}

static void	check_textures(char **textures)
{
	int		ints[2];
	char	**tmp;

	ints[0] = -1;
	while (textures[++ints[0]])
	{
		tmp = ft_split(textures[ints[0]], ' ');
		if (tmp[2])
		{
			ft_free_split(tmp);
			ft_free_split(textures);
			ft_error("Invalid texture path");
		}
		ints[1] = open(tmp[1], O_RDONLY);
		if (ints[1] < 0)
		{
			ft_free_split(tmp);
			ft_free_split(textures);
			ft_error("Could not open texture file");
		}
		ft_free(textures[ints[0]]);
		textures[ints[0]] = ft_strdup(tmp[1]);
		ft_free_split(tmp);
		close(ints[1]);
	}
}

static char	**import_textures(char **file)
{
	char	**out;
	int		i;

	i = -1;
	out = malloc(sizeof(char *) * 5);
	out[0] = NULL;
	out[1] = NULL;
	out[2] = NULL;
	out[3] = NULL;
	out[4] = NULL;
	while (file[++i])
	{
		if (file[i][0] == 'N' && file[i][1] == 'O' && out[0] == NULL)
			out[0] = ft_strdup(file[i]);
		else if (file[i][0] == 'S' && file[i][1] == 'O' && out[1] == NULL)
			out[1] = ft_strdup(file[i]);
		else if (file[i][0] == 'W' && file[i][1] == 'E' && out[2] == NULL)
			out[2] = ft_strdup(file[i]);
		else if (file[i][0] == 'E' && file[i][1] == 'A' && out[3] == NULL)
			out[3] = ft_strdup(file[i]);
	}
	return (out);
}

void	parse_textures(t_game *game)
{
	char	**textures;
	int		i;

	i = -1;
	textures = import_textures(game->mapdata->tmp);
	while (++i < 4)
		if (!textures[i])
			ft_error("Missing texture");
	check_textures(textures);
	i = 0;
	while (textures[i])
	{
		printf("Texture \"%s\" found\n", textures[i++]);
	}
	ft_free_split(textures);
}
