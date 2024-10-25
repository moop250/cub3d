/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:46:14 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/25 22:32:16 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	handle_movement(t_game *game, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, FORWARD);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, BACKWARD);
	else if (keycode == KEY_A)
		move_player(game, LEFT);
	else if (keycode == KEY_D)
		move_player(game, RIGHT);
}

static void	handle_rotation(t_game *game, int keycode)
{
	double	angle;

	if (keycode == KEY_RIGHT)
		angle = ROTATION_DEGREE;
	else if (keycode == KEY_LEFT)
		angle = -ROTATION_DEGREE;
	if (angle != 0.0)
		rotate_player(game, angle);
}

int	process_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		cleanup_game(game);
		return (0);
	}
	handle_movement(game, keycode);
	handle_rotation(game, keycode);
	return (1);
}
