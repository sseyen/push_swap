/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:12:59 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 14:44:00 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char str[] = "Hello, World!";
//     char *result1 = memchr(str, 'o', strlen(str));
//     char *result2 = ft_memchr(str, 'o', strlen(str));
//     if (result1)
//         printf("memchr: %ld\n", result1 - str);
//     else
//         printf("memchr: Character not found.\n");
//     if (result2)
//         printf("ft_memchr: %ld\n", result2 - str);
//     else
//         printf("ft_memchr: Character not found.\n");
//     char *result3 = memchr(str, 'z', strlen(str));
//     char *result4 = ft_memchr(str, 'z', strlen(str));
//     if (result3)
//         printf("memchr: %ld\n", result3 - str);
//     else
//         printf("memchr: Character not found.\n");
//     if (result4)
//         printf("ft_memchr: "%ld\n", result4 - str);
//     else
//         printf("Custom ft_memchr: Character 'z' not found.\n");
//     return 0;
// }