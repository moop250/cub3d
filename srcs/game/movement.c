/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:19:47 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/30 14:30:05 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static bool	collision_check(t_game *game, double new_x, double new_y)
{
	int		map_x;
	int		map_y;

	map_x = (int)(new_x);
	map_y = (int)(new_y);
	if (game->mapdata->map[map_y][map_x] == '1')
		return (false);
	return (true);
}

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
	double		new_x;
	double		new_y;

	player = &game->mapdata->player;
	move_step = dir * STEP_SIZE;
	strafe_step = strafe * STEP_SIZE;
	new_x += (player->dir.x * move_step)
		+ ((player->dir.x + HALF_PI) * strafe_step);
	new_y += (player->dir.y * move_step)
		+ ((player->dir.y + HALF_PI) * strafe_step);

	if (!collision_check(game, new_x, new_y))
	{
		player->pos.x = new_x;
		player->pos.y = new_y;
	}
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
