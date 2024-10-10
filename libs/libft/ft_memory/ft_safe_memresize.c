/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_memresize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:17:27 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/10 15:23:21 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Resizes a memory block.
 *
 * This function reallocates a memory block to a new size. If the new size is zero,
 * it frees the memory block and returns NULL. If the original pointer is NULL,
 * it simply allocates a new block of the specified size. Otherwise, it allocates
 * a new block, copies the contents of the old block to the new block (up to the
 * smaller of the old and new sizes), frees the old block, and returns the new block.
 *
 * @param ptr The original memory block.
 * @param old_size The size of the original memory block.
 * @param new_size The size of the new memory block.
 * @param error_message The error message to be printed out
 * @return A pointer to the new memory block, or NULL if allocation fails or new_size is zero.
 */
void	*ft_safe_memresize(void *ptr, size_t old_size,
	size_t new_size, char *error_message)
{
	void	*new_ptr;

	new_ptr = ft_memresize(ptr, old_size, new_size);
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
