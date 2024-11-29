/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:25:37 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/10 21:30:52 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_strchr(charset, s[i]))
		i++;
	return (i);
}
