/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:40:44 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/11/18 11:43:45 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Free a pointer and print a message to stderr, always return NULL
void	*ft_free_msg(void *ptr, char *msg)
{
	if (ptr)
		free(ptr);
	if (msg)
		ft_putendl_fd(msg, 2);
	return (NULL);
}

// Free a pointer and return a boolean value
bool	ft_free_bool(void *ptr, char *msg, bool flag)
{
	ft_free_msg(ptr, msg);
	return (flag);
}

int	get_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
