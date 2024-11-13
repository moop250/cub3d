/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:46:14 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/13 18:52:47 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	exit_game(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, FORWARD);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, BACKWARD);
	else if (keycode == KEY_A)
		move_player(game, LEFT);
	else if (keycode == KEY_D)
		move_player(game, RIGHT);
	else if (keycode == KEY_RIGHT)
		rotate_player(game, RIGHT);
	else if (keycode == KEY_LEFT)
		rotate_player(game, LEFT);
	return (0);
}
