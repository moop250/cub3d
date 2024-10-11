/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:20:51 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/10 15:23:12 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_safe_realloc(void *ptr, size_t size, char *error_message)
{
	void	*new_ptr;

	new_ptr = ft_realloc(ptr, size);
	if (!new_ptr)
	{
		if (error_message)
		{
			ft_putstr_fd(error_message, STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
		}
		exit(EXIT_FAILURE);
	}
	return (new_ptr);
}
