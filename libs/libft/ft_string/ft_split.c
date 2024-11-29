/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:14:40 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/10 13:48:27 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_count_words(char const *str, char sep)
{
	size_t	wc;
	int		in_word;

	if (!str)
		return (0);
	wc = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == sep)
		{
			if (in_word)
				in_word = 0;
		}
		else if (!in_word)
		{
			wc++;
			in_word = 1;
		}
		str++;
	}
	return (wc);
}

static size_t	ft_wordlen(char const *str, char sep)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

/*
returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer
*/

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**strs;

	strs = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strs || !s)
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
		{
			strs[++j] = ft_strndup(s + i, ft_wordlen(s + i, c));
			if (strs[j] == NULL)
			{
				while (--j >= 0)
					free(strs[j]);
				free(strs);
				return (NULL);
			}
		}
	}
	strs[++j] = NULL;
	return (strs);
}
