/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:07:25 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/08/12 22:22:56 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strisalnum(const char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
