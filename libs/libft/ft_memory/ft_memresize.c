/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:58:27 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/10 15:34:20 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * Resizes a memory block.
 *
 * This function reallocates a memory block to a new size.
 * If the new size is zero, it frees the memory block
 * and returns NULL.
 * If the original pointer is NULL, it simply allocates
 * a new block of the specified size. Otherwise, it allocates
 * a new block, copies the contents of the old block to the new block
 * (up to the smaller of the old and new sizes),
 * frees the old block, and returns the new block.
 *
 * @param ptr The original memory block.
 * @param old_size The size of the original memory block.
 * @param new_size The size of the new memory block.
 * @return A pointer to the new memory block,
 * or NULL if allocation fails or new_size is zero.
 */
void	*ft_memresize(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
