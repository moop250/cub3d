/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:51:12 by hlibine           #+#    #+#             */
/*   Updated: 2024/12/09 15:46:40 by dcaro-ro         ###   ########.fr       */
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
	steps[0] == move_step
	steps[1] == strafe_step
*/
void	move_player(t_game *game, t_move dir)
{
	t_player	*player;
	double		steps[2];
	t_vector	new_pos;

	steps[0] = 0;
	steps[1] = 0;
	player = &game->mapdata->player;
	if (MOVE_SPEED >= 0.0 && MOVE_SPEED <= 1.0)
	{
		if (dir == FORWARD)
			steps[0] = MOVE_SPEED;
		else if (dir == BACKWARD)
			steps[0] = -MOVE_SPEED;
		else if (dir == LEFT)
			steps[1] = MOVE_SPEED;
		else if (dir == RIGHT)
			steps[1] = -MOVE_SPEED;
		else
			return ;
	}
	new_pos.x = player->pos.x + (player->dir.x * steps[0])
		- (player->dir.y * steps[1]);
	new_pos.y = player->pos.y + (player->dir.y * steps[0])
		+ (player->dir.x * steps[1]);
	collision(game, new_pos.x, new_pos.y);
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
