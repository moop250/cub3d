/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaro-ro <dcaro-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:08:01 by dcaro-ro          #+#    #+#             */
/*   Updated: 2024/06/10 13:52:27 by dcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*buffer1;
	const unsigned char	*buffer2;

	i = 0;
	buffer1 = (const unsigned char *)s1;
	buffer2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (buffer1[i] != buffer2[i])
			return (buffer1[i] - buffer2[i]);
		i++;
	}
	return (0);
}
/* declare pointers for byte-wise comparison, iterate through the memory
	blocks up to n bytes, return the difference if a value is found or
	0 if no differences are found after n bytes*/
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf1[] = "Hello, World!";
	char buf2[] = "Hello, World!";
	char buf3[] = "Hello, There!";
	size_t size = 13;

	// Test with identical memory blocks
	int result1 = ft_memcmp(buf1, buf2, size);
	int std1 = memcmp(buf1, buf2, size);
	printf("Identical memory blocks (ft_memcmp) : %d\n", result1);
	printf("Identical memory blocks (memcmp): %d\n\n", std1);

	// Test with different memory blocks
	int result2 = ft_memcmp(buf1, buf3, size);
	int std2 = memcmp(buf1, buf3, size);
	printf("Different memory blocks (ft_memcmp): %d\n", result2);
	printf("Different memory blocks (memcmp): %d\n", std2);

	return 0;
}
*/
