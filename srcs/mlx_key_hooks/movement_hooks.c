/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:14:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/15 16:18:33 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_hook_up(int keycode, t_game *game)
{
	t_move_bools	*dir;

	if (keycode == KEY_ESC)
		exit_game(game);
	dir = &game->move;
	if (keycode == KEY_W && !dir->forward)
		dir->forward = true;
	else if (keycode == KEY_S && !dir->backward)
		dir->backward = true;
	else if (keycode == KEY_A && !dir->left)
		dir->left = true;
	else if (keycode == KEY_D && !dir->right)
		dir->right = true;
	else if (keycode == KEY_RIGHT && !dir->rotate_right)
		dir->rotate_right = true;
	else if (keycode == KEY_LEFT && !dir->rotate_left)
		dir->rotate_left = true;
	if (dir->forward || dir->backward || dir->left || dir->right)
		dir->is_moving = true;
	if (dir->rotate_right || dir->rotate_left)
		dir->is_rotating = true;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	t_move_bools	*dir;

	dir = &game->move;
	if (keycode == KEY_W && dir->forward)
		dir->forward = false;
	else if (keycode == KEY_S && dir->backward)
		dir->backward = false;
	else if (keycode == KEY_A && dir->left)
		dir->left = false;
	else if (keycode == KEY_D && dir->right)
		dir->right = false;
	else if (keycode == KEY_RIGHT && dir->rotate_right)
		dir->rotate_right = false;
	else if (keycode == KEY_LEFT && dir->rotate_left)
		dir->rotate_left = false;
	if (!dir->forward || !dir->backward || !dir->left || !dir->right)
		dir->is_moving = false;
	if (!dir->rotate_right || !dir->rotate_left)
		dir->is_rotating = false;
	return (0);
}
