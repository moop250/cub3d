/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:26:42 by hlibine           #+#    #+#             */
/*   Updated: 2024/10/21 15:00:27 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_error(const char *msg)
{
	freeall(NULL);
	ft_printf("Error: %s\n", msg);
	exit(1);
}

// Free a pointer and print a message to stderr, always return NULL
void	*ft_free_msg(void *ptr, const char *msg)
{
	if (ptr)
		free(ptr);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putchar_fd('\n', 2);
	}
	return (NULL);
}

// Free a pointer and return a boolean value
bool	ft_free_bool(void *ptr, const char *msg, bool flag)
{
	ft_free_msg(ptr, msg);
	return (flag);
}
