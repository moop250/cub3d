/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:39:11 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/25 22:29:57 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_move(t_game *game, t_vector *move, t_move dir)
{
	if (dir == FORWARD)
	{
		move->x = game->mapdata->player.dir.x * MOVE_SPEED;
		move->y = game->mapdata->player.dir.y * MOVE_SPEED;
	}
	else if (dir == BACKWARD)
	{
		move->x = -game->mapdata->player.dir.x * MOVE_SPEED;
		move->y = -game->mapdata->player.dir.y * MOVE_SPEED;
	}
	else if (dir == LEFT)
	{
		move->x = game->mapdata->player.plane.x * MOVE_SPEED;
		move->y = game->mapdata->player.plane.y * MOVE_SPEED;
	}
	else if (dir == RIGHT)
	{
		move->x = -game->mapdata->player.plane.x * MOVE_SPEED;
		move->y = -game->mapdata->player.plane.y * MOVE_SPEED;
	}
	else
	{
		move->x = 0;
		move->y = 0;
	}
}

void	move_player(t_game *game, t_move dir)
{
	t_vector	move;
	t_vector	new_pos;
	t_coord		old_pos;
	int			pos_x;
	int			pos_y;

	init_move(game, &move, dir);
	new_pos.x = game->mapdata->player.pos.x + move.x;
	new_pos.y = game->mapdata->player.pos.y + move.y;
	pos_x = (int)new_pos.x;
	pos_y = (int)new_pos.y;
	old_pos.x = (int)game->mapdata->player.pos.x;
	if (new_pos.y >= 0 && new_pos.y < game->height
		&& game->mapdata->map[pos_y][old_pos.x] != '1')
	{
		game->mapdata->player.pos.y = new_pos.y;
	}
	old_pos.y = (int)game->mapdata->player.pos.y;
	if (new_pos.x >= 0 && new_pos.x < game->width
		&& game->mapdata->map[old_pos.y][pos_x] != '1')
	{
		game->mapdata->player.pos.x = new_pos.x;
	}
}

void	rotate_player(t_game *game, double angle)
{
	t_vector	old_dir;
	t_vector	old_plane;
	double		rad_angle;

	if (angle != 0.0)
	{
		rad_angle = angle * (FT_PI / 180);
		old_dir = game->mapdata->player.dir;
		game->mapdata->player.dir.x = old_dir.x * cos(rad_angle)
			- old_dir.y * sin(rad_angle);
		game->mapdata->player.dir.y = old_dir.x * sin(rad_angle)
			+ old_dir.y * cos(rad_angle);
		old_plane = game->mapdata->player.plane;
		game->mapdata->player.plane.x = old_plane.x * cos(rad_angle)
			- old_plane.y * sin(rad_angle);
		game->mapdata->player.plane.y = old_plane.x * sin(rad_angle)
			+ old_plane.y * cos(rad_angle);
	}
}
