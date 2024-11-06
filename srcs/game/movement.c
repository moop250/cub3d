/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:19:47 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/06 17:36:55 by dcaro-ro         ###   ########.fr       */
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
		return (true);
	return (false);
}

/*
	move(game, FORWARD) to move forward.
	move(game, BACKWARD) to move backward.
	move(game, RIGHT) to strafe right.
	move(game, LEFT) to strafe left.
*/
void	move_player(t_game *game, t_move dir)
{
	t_player	*player;
	double		move_step;
	double		strafe_step;
	double		new_x;
	double		new_y;

	move_step = 0;
	strafe_step = 0;
	player = &game->mapdata->player;
	if (dir == FORWARD)
		move_step = STEP_SIZE;
	else if (dir == BACKWARD)
		move_step = -STEP_SIZE;
	else if (dir == LEFT)
		strafe_step = -STEP_SIZE;
	else if (dir == RIGHT)
		strafe_step = STEP_SIZE;
	new_x = (player->dir.x * move_step) + ((player->dir.x + HALF_PI) * strafe_step);
	new_y = (player->dir.y * move_step) + ((player->dir.y + HALF_PI) * strafe_step);
	if (!collision_check(game, new_x, new_y))
	{
		player->pos.x = new_x;
		player->pos.y = new_y;
	}
}

/*
	rotate(game, RIGHT) to rotate right.
	rotate(game, LEFT) to rotate left.
*/
void	rotate_player(t_game *game, t_move dir)
{
	t_player	*player;

	player = &game->mapdata->player;
	if (dir == LEFT)
	{
		player->angle -= 0.1;
		if (player->angle < 0)
			player->angle += 2 * PI;
	}
	else if (dir == RIGHT)
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

// static bool	collision_check(t_game *game, double new_x, double new_y)
// {
// 	int		map_x;
// 	int		map_y;

// 	map_x = (int)(new_x);
// 	map_y = (int)(new_y);
// 	if (game->mapdata->map[map_y][map_x] == '1')
// 		return (true);
// 	return (false);
// }

// /*
// 	move(game, 1, 0) to move forward.
// 	move(game, -1, 0) to move backward.
// 	move(game, 0, 1) to strafe right.
// 	move(game, 0, -1) to strafe left.
// */
// void	move(t_game *game, int dir, int strafe)
// {
// 	t_player	*player;
// 	double		move_step;
// 	double		strafe_step;
// 	double		new_x;
// 	double		new_y;

// 	player = &game->mapdata->player;
// 	move_step = dir * STEP_SIZE;
// 	strafe_step = strafe * STEP_SIZE;
// 	new_x += (player->dir.x * move_step)
// 		+ ((player->dir.x + HALF_PI) * strafe_step);
// 	new_y += (player->dir.y * move_step)
// 		+ ((player->dir.y + HALF_PI) * strafe_step);

// 	if (!collision_check(game, new_x, new_y))
// 	{
// 		player->pos.x = new_x;
// 		player->pos.y = new_y;
// 	}
// }

// /*
// 	rotate(game, 1) to rotate right.
// 	rotate(game, -1) to rotate left.
// */
// void	rotate(t_game *game, int dir)
// {
// 	t_player	*player;

// 	player = &game->mapdata->player;
// 	if (dir == -1)
// 	{
// 		player->angle -= 0.1;
// 		if (player->angle < 0)
// 			player->angle += 2 * PI;
// 	}
// 	else if (dir == 1)
// 	{
// 		player->angle += 0.1;
// 		if (player->angle > 2 * PI)
// 			player->angle -= 2 * PI;
// 	}
// 	else
// 		return ;
// 	player->dir.x = cos(player->angle);
// 	player->dir.y = sin(player->angle);
// }


/*
	move(game, 1, 0) to move forward.
	move(game, -1, 0) to move backward.
	move(game, 0, 1) to strafe right.
	move(game, 0, -1) to strafe left.
*/
