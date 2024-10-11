/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:07:43 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/10 15:17:13 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_safe_malloc(size_t size, char *error_message)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		if (error_message)
		{
			ft_putstr_fd(error_message, STDERR_FILENO);
			ft_putstr_fd("\n", STDERR_FILENO);
		}
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
