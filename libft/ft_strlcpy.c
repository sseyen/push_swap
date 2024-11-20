/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:04:02 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/05 16:40:42 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char src[] = "Hello, world!";
//     char dst_ft[20];
//     char dst_orig[20];
//     size_t size = 0;
//     size_t ft_len = ft_strlcpy(dst_ft, src, size);
//     printf("ft_strlcpy: \n");
//     printf("Original string: \"%s\"\n", src);
//     printf("Result: \"%s\"\n", dst_ft);
//     printf("Tried length: %zu\n\n", ft_len);
//     size_t orig_len = strlcpy(dst_orig, src, size);
//     printf("strlcpy: \n");
//     printf("Original string: \"%s\"\n", src);
//     printf("Result: \"%s\"\n", dst_orig);
//     printf("Tried length: %zu\n", orig_len);
//     return 0;
// }