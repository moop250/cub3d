/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_strs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:06:08 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/08/03 12:22:03 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../include/libft.h"

static size_t	get_total_length(unsigned int count, va_list args)
{
	size_t			len;
	unsigned int	i;
	char			*str;
	va_list			args_copy;

	va_copy(args_copy, args);
	len = 0;
	i = 0;
	while (i < count)
	{
		str = va_arg(args_copy, char *);
		len += ft_strlen(str);
		i++;
	}
	va_end(args_copy);
	return (len);
}

char	*ft_concat_strs(unsigned int count, ...)
{
	va_list			args;
	unsigned int	i;
	char			*dest;
	char			*ptr;
	char			*str;

	va_start(args, count);
	dest = malloc(get_total_length(count, args) + 1);
	va_end(args);
	if (!dest)
		return (NULL);
	ptr = dest;
	i = 0;
	while (i < count)
	{
		str = va_arg(args, char *);
		while (*str)
			*ptr++ = *str++;
		i++;
	}
	va_end(args);
	*ptr = '\0';
	return (dest);
}
