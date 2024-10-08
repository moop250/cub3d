/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:20:21 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/02 12:43:55 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putnbr_hex(unsigned long int n)
{
	int		len;
	char	*hex_chars;

	len = 0;
	hex_chars = "0123456789abcdef";
	if (n >= 16)
		len += ft_putnbr_hex(n / 16);
	len += ft_putchar(hex_chars[n % 16]);
	return (len);
}

int	ft_handle_ptr(va_list args)
{
	char	*str;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr)
	{
		ft_putstr("0x");
		return (ft_putnbr_hex((unsigned long)ptr) + 2);
	}
	str = "0x0";
	return (ft_putstr(str));
}
