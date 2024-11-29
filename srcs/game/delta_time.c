/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:51:12 by hlibine           #+#    #+#             */
/*   Updated: 2024/11/15 20:51:46 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	get_current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((double)now.tv_sec + (double)now.tv_usec / 1000000.0);
}
