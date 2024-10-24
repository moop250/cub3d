/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:26:42 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/24 11:24:35 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_error(const char *msg)
{
	freeall();
	printf("Error: %s\n", msg);
	exit(1);
}

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
