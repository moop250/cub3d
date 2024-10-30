/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:27:24 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/30 13:22:11 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	print_player(t_player *player)
{
	printf("      Pos: %f, %f\n", player->pos.x, player->pos.y);
	printf("      Angle: %f\n", player->angle);
	printf("      Dirs: %f, %f\n", player->dir.x, player->dir.y);
	printf("      Plane: %f, %f\n", player->plane.x, player->plane.y);
}

static void	print_xpm(t_xpm *xpm)
{
	printf("      img: %p\n", xpm->img);
	printf("      width: %d\n", xpm->width);
	printf("      height: %d\n", xpm->height);
}

static void	print_map(char **map)
{
	unsigned int	i;

	i = 0;
	while (map[i])
	{
		printf("      %s\n", map[i]);
		i++;
	}
}

// static void	print_colors(int colors[2][3])
// {
// 	printf("Floor color: R=%d, G=%d, B=%d\n",
// 		colors[0][0], colors[0][1], colors[0][2]);
// 	printf("Ceiling color: R=%d, G=%d, B=%d\n",
// 		colors[1][0], colors[1][1], colors[1][2]);
// }

static void	print_mlx(t_mlx *mlx)
{
	if (!mlx)
	{
		ft_putendl_fd("MLX is not properly initialized", 2);
		return ;
	}
	printf("  MLX:\n");
	printf("    ptr: %p\n", mlx->ptr);
	printf("    win_ptr: %p\n", mlx->win_ptr);
	printf("    img_ptr: %p\n", mlx->img_ptr);
	printf("    addr: %p\n", mlx->addr);
	printf("    bpp: %d\n", mlx->bpp);
	printf("    size_line: %d\n", mlx->size_line);
	printf("    endian: %d\n", mlx->endian);
	printf("\n");
}

void	print_game(t_game *game)
{
	if (!game || !game->mapdata || !game->textures)
	{
		ft_putendl_fd("Game is not properly initialized", 2);
		return ;
	}
	ft_putstr_fd("Game Structure:\n", 1);
	printf("  Width: %d, Height: %d\n", game->width, game->height);
	print_mlx(&game->mlx);
	printf("  Mapdata:\n");
	print_map(game->mapdata->map);
	print_player(&game->mapdata->player);
	printf("Floor color: R=%d, G=%d, B=%d\n", game->mapdata->colors[0][0],
		game->mapdata->colors[0][1], game->mapdata->colors[0][2]);
	printf("Ceiling color: R=%d, G=%d, B=%d\n", game->mapdata->colors[1][0],
		game->mapdata->colors[1][1], game->mapdata->colors[1][2]);
	printf("  Textures:\n");
	printf("    North:\n");
	print_xpm(&game->textures->north);
	printf("    South:\n");
	print_xpm(&game->textures->south);
	printf("    East:\n");
	print_xpm(&game->textures->east);
	printf("    West:\n");
	print_xpm(&game->textures->west);
}
