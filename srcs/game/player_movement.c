/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/19 16:26:53 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_corner(t_game *game, double x, double y)
{
	if (game->mapdata->map[(int)(y + COLLISION_RADIUS)]
		[(int)(x + COLLISION_RADIUS)] != '0')
		return (1);
	if (game->mapdata->map[(int)(y - COLLISION_RADIUS)]
		[(int)(x - COLLISION_RADIUS)] != '0')
		return (1);
	if (game->mapdata->map[(int)(y - COLLISION_RADIUS)]
		[(int)(x + COLLISION_RADIUS)] != '0')
		return (1);
	if (game->mapdata->map[(int)(y + COLLISION_RADIUS)]
		[(int)(x - COLLISION_RADIUS)] != '0')
		return (1);
	if (game->mapdata->map[(int)(y + COLLISION_RADIUS)]
		[(int)(x + COLLISION_RADIUS)] != '0')
		return (1);
	return (0);
}

static int	is_collision(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (game->mapdata->map[map_y][map_x] != '0')
		return (1);
	if (game->mapdata->map[map_y][(int)(x + COLLISION_RADIUS)] != '0')
		return (1);
	if (game->mapdata->map[(int)(y + COLLISION_RADIUS)][map_x] != '0')
		return (1);
	return (check_corner(game, x, y));
}

static void	collision(t_game *game, double new_x, double new_y)
{
	t_player	*player;

	player = &game->mapdata->player;
	if (!is_collision(game, new_x, new_y))
		player->pos = (t_vector){new_x, new_y};
	else
	{
		if (!is_collision(game, new_x, player->pos.y))
			player->pos.x = new_x;
		if (!is_collision(game, player->pos.x, new_y))
			player->pos.y = new_y;
	}
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
		move_step = MOVE_SPEED;
	else if (dir == BACKWARD)
		move_step = -MOVE_SPEED;
	else if (dir == LEFT)
		strafe_step = MOVE_SPEED;
	else if (dir == RIGHT)
		strafe_step = -MOVE_SPEED;
	else
		return ;
	new_x = player->pos.x + (player->dir.x * move_step)
		- (player->dir.y * strafe_step);
	new_y = player->pos.y + (player->dir.y * move_step)
		+ (player->dir.x * strafe_step);
	collision(game, new_x, new_y);
}

/*
	rotate(game, TURN_RIGHT) to rotate right.
	rotate(game, TURN_LEFT) to rotate left.
*/
void	rotate_player(t_game *game, t_move dir)
{
	t_vector	*plane;
	t_player	*player;
	double		old_plane_x;
	double		rotation_angle;

	plane = &game->mapdata->player.plane;
	player = &game->mapdata->player;
	if (dir == TURN_LEFT)
		rotation_angle = ROTATE_SPEED;
	else if (dir == TURN_RIGHT)
		rotation_angle = -ROTATE_SPEED;
	else
		return ;
	player->angle += rotation_angle;
	if (player->angle < 0)
		player->angle += TWO_PI;
	else if (player->angle > TWO_PI)
		player->angle -= TWO_PI;
	old_plane_x = plane->x;
	plane->x = plane->x * cos(rotation_angle) - plane->y * sin(rotation_angle);
	plane->y = old_plane_x * sin(rotation_angle)
		+ plane->y * cos(rotation_angle);
	player->dir.x = cos(player->angle);
	player->dir.y = sin(player->angle);
}
