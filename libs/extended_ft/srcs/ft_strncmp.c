/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:46:10 by hlibine           #+#    #+#             */
/*   Updated: 2024/05/14 15:05:29 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_ft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (*str1 && (*str1 == *str2) && (--n > 0))
	{
		str1++;
		str2++;
	}
	if (n == 0)
		return (0);
	return (*(const unsigned char *)str1 - *(const unsigned char *)str2);
}
