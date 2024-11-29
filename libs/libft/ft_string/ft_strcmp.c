/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:01:42 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/08/02 10:11:33 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	int				result;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}
