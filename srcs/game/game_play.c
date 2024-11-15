/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:31:30 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/15 20:58:40 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_dir(t_game *game)
{
	t_move_bools	*dir;

	dir = &game->move;
	if (dir->forward)
		move_player(game, FORWARD);
	if (dir->backward)
		move_player(game, BACKWARD);
	if (dir->left)
		move_player(game, LEFT);
	if (dir->right)
		move_player(game, RIGHT);
	if (dir->rotate_right)
		rotate_player(game, TURN_RIGHT);
	if (dir->rotate_left)
		rotate_player(game, TURN_LEFT);
}

int	game_play(t_game *game)
{
	double	current_time;
	double	elapsed_time;

	current_time = get_current_time();
	elapsed_time = current_time - game->last_time;
	if (elapsed_time < FRAME_TIME)
	{
		if (game->move.is_moving || game->move.is_rotating)
		{
			move_dir(game);
			ft_bzero(game->mlx.addr,
				game->width * game->height * (game->mlx.bpp / 8));
			ray_casting(game);
			mlx_put_image_to_window(game->mlx.ptr,
				game->mlx.win_ptr, game->mlx.img_ptr, 0, 0);
		}
	}
	game->last_time = current_time;
	return (0);
}
