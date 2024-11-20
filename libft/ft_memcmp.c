/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:29:43 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 15:10:39 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return ((ptr1[i] - ptr2[i]));
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str1[] = "Hello, World!";
//     char str2[] = "Hello, World!";
//     int result1 = memcmp(str1, str2, 13);
//     int result2 = ft_memcmp(str1, str2, 13);
//     printf("Test 1 (identical strings):\n");
//     printf("Original memcmp: %d\n", result1);
//     printf("Custom ft_memcmp: %d\n\n", result2);
//     char str3[] = "Hello, World!";
//     char str4[] = "Hello, Earth!";
//     result1 = memcmp(str3, str4, 13);
//     result2 = ft_memcmp(str3, str4, 13);
//     printf("Test 2 (different strings):\n");
//     printf("Original memcmp: %d\n", result1);
//     printf("Custom ft_memcmp: %d\n\n", result2);
//     result1 = memcmp(str3, str4, 7);
//     result2 = ft_memcmp(str3, str4, 7);
//     printf("Test 3 (comparing first 7 bytes):\n");
//     printf("Original memcmp: %d\n", result1);
//     printf("Custom ft_memcmp: %d\n\n", result2);
//     char str5[] = "ABCDEF";
//     char str6[] = "123456";
//     result1 = memcmp(str5, str6, 6);
//     result2 = ft_memcmp(str5, str6, 6);
//     printf("Test 4 (completely different strings):\n");
//     printf("Original memcmp: %d\n", result1);
//     printf("Custom ft_memcmp: %d\n\n", result2);
//     return 0;
// }