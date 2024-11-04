/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:45:04 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/04 15:37:52 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	game_play(t_game *game)
{
	ft_bzero(game->mlx.addr, game->width * game->height * (game->mlx.bpp / 8));
	ray_casting(game);
	//render_scene(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win_ptr,
		game->mlx.img_ptr, 0, 0);
}
