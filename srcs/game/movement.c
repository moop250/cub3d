/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:19:47 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/30 13:23:37 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
	move(game, 1, 0) to move forward.
	move(game, -1, 0) to move backward.
	move(game, 0, 1) to strafe right.
	move(game, 0, -1) to strafe left.
*/
void	move(t_game *game, int dir, int strafe)
{
	t_player	*player;
	double		move_step;
	double		strafe_step;

	player = &game->mapdata->player;
	move_step = dir * STEP_SIZE;
	strafe_step = strafe * STEP_SIZE;
	player->pos.x += player->dir.x * move_step;
	player->pos.y += player->dir.y * move_step;
	player->pos.x += (player->dir.x + HALF_PI) * strafe_step;
	player->pos.y += (player->dir.y + HALF_PI) * strafe_step;
}

/*
	rotate(game, 1) to rotate right.
	rotate(game, -1) to rotate left.
*/
void	rotate(t_game *game, int dir)
{
	t_player	*player;

	player = &game->mapdata->player;
	if (dir == -1)
	{
		player->angle -= 0.1;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
	else if (dir == 1)
	{
		player->angle += 0.1;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
	}
	else
		return ;
	player->dir.x = cos(player->angle);
	player->dir.y = sin(player->angle);
}
