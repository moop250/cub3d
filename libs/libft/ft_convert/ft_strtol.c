/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:05:38 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/11 11:43:29 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	get_digit(int c, int base)
{
	int	digit;

	if (base < 2 || base > 36)
		return (-1);
	digit = -1;
	if (c >= '0' && c <= '9')
		digit = c - '0';
	else if (c >= 'a' && c <= 'f')
		digit = c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		digit = c - 'A' + 10;
	if (digit < base)
		return (digit);
	return (-1);
}

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (ft_isspace((unsigned char)**str))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static void	parse_base(const char **str, int *base)
{
	if (*base == 0)
	{
		if (**str == '0')
		{
			(*str)++;
			if (**str == 'x' || **str == 'X')
			{
				*base = 16;
				(*str)++;
			}
			else
				*base = 8;
		}
		else
			*base = 10;
	}
	else if (*base == 16)
	{
		if (**str == '0' && ((*str)[1] == 'x' || (*str)[1] == 'X'))
			*str += 2;
	}
}

static long	compute_result(const char *str, int base, int sign, char **endptr)
{
	long	result;
	int		digit;

	result = 0;
	digit = get_digit(*str, base);
	while (digit >= 0)
	{
		if (result > (FT_LONG_MAX - digit) / base)
		{
			if (sign == 1)
				return (FT_LONG_MAX);
			else
				return (-FT_LONG_MAX - 1L);
		}
		result = result * base + digit;
		str++;
		digit = get_digit(*str, base);
	}
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	int	sign;

	if (base < 2 || base > 36)
		return (0);
	sign = parse_sign(&str);
	parse_base(&str, &base);
	return (compute_result(str, base, sign, endptr));
}
