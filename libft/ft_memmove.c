/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:20:32 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 17:43:04 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src && n > 0)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char src1[50] = "Hello, World! How are you?";
//     char src2[50] = "Hello, World! How are you?";
//     printf("Before memmove:\n");
//     printf("src1 (using ft_memmove): %s\n", src1);
//     printf("src2 (using memmove): %s\n\n", src2);
//     ft_memmove(src1 + 6, src1, 12);
//     memmove(src2 + 6, src2, 12);
//     printf("After memmove:\n");
//     printf("src1 (using ft_memmove): %s\n", src1);
//     printf("src2 (using memmove): %s\n", src2);
//     printf("\nAdditional test (non-overlapping):\n");
//     char dest1[50] = {0};
//     char dest2[50] = {0};
//     ft_memmove(dest1, src1, 12);
//     memmove(dest2, src2, 12);
//     printf("dest1 (using ft_memmove): %s\n", dest1);
//     printf("dest2 (using memmove): %s\n", dest2);
//     return 0;
// }