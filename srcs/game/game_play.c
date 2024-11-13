/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:31:30 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 18:51:20 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	game_play(t_game *game)
{
	ft_bzero(game->mlx.addr, game->width * game->height * (game->mlx.bpp / 8));
	ray_casting(game);
	mlx_put_image_to_window(game->mlx.ptr,
		game->mlx.win_ptr, game->mlx.img_ptr, 0, 0);
	return (0);
}
