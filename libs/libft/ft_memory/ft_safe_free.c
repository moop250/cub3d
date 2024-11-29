/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:04:01 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/07/08 13:53:59 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libft.h"

void	*ft_safe_free(unsigned int num_ptrs, ...)
{
	va_list			args;
	void			*ptr;
	unsigned int	i;

	va_start(args, num_ptrs);
	i = 0;
	while (i < num_ptrs)
	{
		ptr = va_arg(args, void *);
		if (ptr)
			free(ptr);
		i++;
	}
	va_end(args);
	return (NULL);
}
