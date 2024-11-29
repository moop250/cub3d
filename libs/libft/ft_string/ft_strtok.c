/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:55:05 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/11 11:55:56 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*next_token = NULL;
	char		*start;
	char		*end;

	if (str)
		next_token = str;
	if (!next_token)
		return (NULL);
	start = next_token;
	end = ft_strchr(start, *delim);
	if (!end)
	{
		next_token = NULL;
		return (start);
	}
	*end = '\0';
	next_token = end + 1;
	while (*next_token && (ft_strchr(delim, *next_token) != NULL))
		next_token++;
	return (start);
}
