/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:18:57 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/02 12:43:45 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_num_length(unsigned int num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

static char	*ft_itoa_hex(unsigned int num, int is_upper)
{
	int			i;
	int			len;
	char		*hex_buffer;
	char		*hex_chars;

	if (is_upper)
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";
	len = ft_num_length(num, 16);
	hex_buffer = malloc(sizeof(char) * (len + 1));
	if (!hex_buffer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		hex_buffer[i] = hex_chars[num % 16];
		num /= 16;
		i++;
	}
	hex_buffer[i] = '\0';
	return (hex_buffer);
}

int	ft_handle_hex(va_list args, int is_upper)
{
	int				i;
	int				len;
	char			temp;
	char			*hex_buffer;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	hex_buffer = ft_itoa_hex(num, is_upper);
	if (!hex_buffer)
		return (0);
	len = ft_str_length(hex_buffer);
	i = 0;
	while (i < len / 2)
	{
		temp = hex_buffer[i];
		hex_buffer[i] = hex_buffer[len - i - 1];
		hex_buffer[len - i - 1] = temp;
		i++;
	}
	len = ft_putstr(hex_buffer);
	free(hex_buffer);
	return (len);
}
