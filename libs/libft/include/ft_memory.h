/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:56:13 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/10/10 15:25:42 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <unistd.h>
# include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_safe_free(unsigned int num_ptrs, ...);
void	*ft_memresize(void *ptr, size_t old_size, size_t new_size);
void	*ft_free(void *ptr);
void	*ft_safe_malloc(size_t size, char *error_message);
void	*ft_safe_memresize(void *ptr, size_t old_size,
			size_t new_size, char *error_message);
void	*ft_safe_realloc(void *ptr, size_t size, char *error_message);

#endif
