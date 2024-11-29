/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:40:22 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/10 21:14:52 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*current;
	const char	*match_start;
	const char	*needle_pos;

	current = haystack;
	if (!*needle)
		return ((char *)haystack);
	while (*current)
	{
		match_start = current;
		needle_pos = needle;
		while (*current && *needle_pos && *current == *needle_pos)
		{
			current++;
			needle_pos++;
		}
		if (!*needle_pos)
			return ((char *)match_start);
		current = match_start + 1;
	}
	return (NULL);
}
