/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:11:09 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 15:20:42 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src && n > 0)
		return (NULL);
	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char src[20] = "Hello, World!";
//     char dest1[20];
//     char dest2[20];
//     memcpy(dest1, src, strlen(src) + 1);
//     ft_memcpy(dest2, src, strlen(src) + 1);
//     printf("Source: %s\n", src);
//     printf("Destination with original memcpy: %s\n", dest1);
//     printf("Destination with ft_memcpy: %s\n", dest2);
//     return 0;
// }