/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:22:10 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/02 12:44:15 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len += ft_putchar(str[len]);
	return (len);
}

int	ft_str_length(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_isformatspecifier(const char f)
{
	return (f == 'c' || f == 's' || f == 'p' || f == 'd' || f == 'i'
		|| f == 'u' || f == 'x' || f == 'X' || f == '%');
}
