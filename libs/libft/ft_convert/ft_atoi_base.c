/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:13:48 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/11 17:18:00 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_isdigit_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= ('0' + base - 1));
	else
		return ((c >= '0' && c <= '9')
			|| (c >= 'A' && c <= ('A' + base - 11))
			|| (c >= 'a' && c <= ('a' + base - 11)));
}

static int	ft_chartoint(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit_base(*str, base))
	{
		digit = ft_chartoint(*str);
		result = result * base + digit;
		str++;
	}
	return (result * sign);
}
