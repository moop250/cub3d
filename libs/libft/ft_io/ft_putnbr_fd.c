/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:12:20 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/10 13:51:15 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
}
/*
int main(void)
{
	int min = -2147483648;
	int neg = -2548650;
	int pos = 48525605;
	int fd = 1;

	ft_putnbr_fd(min, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(neg, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(pos, fd);
	ft_putchar_fd('\n', fd);

	return 0;
}
*/
