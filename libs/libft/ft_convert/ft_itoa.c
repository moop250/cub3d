/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:43:42 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/10 14:02:21 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = !n;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		len;
	int		is_neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = ft_isneg(n);
	len = ft_intlen(n) + is_neg;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (is_neg)
	{
		n = -n;
		str[0] = '-';
	}
	str[len] = '\0';
	while (n)
	{
		str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
	int x = -2147483648;
	int neg = -259860;
	int pos = 2486910;

	printf("INT_MIN: %i\n", x);
	printf("String: %s\n\n", ft_itoa(x));

	printf("Negative: %i\n", neg);
	printf("String: %s\n\n", ft_itoa(neg));

	printf("Positive: %i\n", pos);
	printf("String: %s\n", ft_itoa(pos));

	return 0;
}
*/
