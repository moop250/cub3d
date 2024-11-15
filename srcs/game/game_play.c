/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:31:30 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/15 16:11:45 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_move	return_dir(t_move_bools *dir)
{
	if (dir->forward)
		return (FORWARD);
	if (dir->backward)
		return (BACKWARD);
	if (dir->left)
		return (LEFT);
	if (dir->right)
		return (RIGHT);
	if (dir->rotate_right)
		return (TURN_RIGHT);
	if (dir->rotate_left)
		return (TURN_LEFT);
	return (-1);
}

int	game_play(t_game *game)
{
	if (game->move.is_moving || game->move.is_rotating)
	{
		move_player(game, return_dir(&game->move));
		rotate_player(game, return_dir(&game->move));
		ft_bzero(game->mlx.addr,
			game->width * game->height * (game->mlx.bpp / 8));
		ray_casting(game);
		mlx_put_image_to_window(game->mlx.ptr,
			game->mlx.win_ptr, game->mlx.img_ptr, 0, 0);
	}
	return (0);
}
