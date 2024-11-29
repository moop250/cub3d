/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:18:30 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/10 13:33:51 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* The strndup() function copies at most n bytes.
If s is longer than n, only n bytes are copied,
and a terminating null byte ('\0') is added */

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s || n <= 0)
		return (NULL);
	len = ft_strlen(s);
	if (n > len)
		n = len;
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
