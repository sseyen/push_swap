/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:44:33 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/24 13:06:44 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && dst_len + i + 1 < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
    char dst1[20];
    char dst2[20];
    size_t result;

    // Test 1: Sufficient buffer size
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    printf("Test 1: Sufficient buffer size\n");
    
    result = strlcat(dst1, " World", sizeof(dst1));
    printf("Original strlcat result: %s, Length: %zu\n", dst1, result);

    result = ft_strlcat(dst2, " World", sizeof(dst2));
    printf("ft_strlcat result: %s, Length: %zu\n\n", dst2, result);

    // Test 2: Exact buffer size
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    printf("Test 2: Exact buffer size\n");

    result = strlcat(dst1, " World", 11);
    printf("Original strlcat result: %s, Length: %zu\n", dst1, result);

    result = ft_strlcat(dst2, " World", 11);
    printf("ft_strlcat result: %s, Length: %zu\n\n", dst2, result);

    // Test 3: Small buffer size
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    printf("Test 3: Small buffer size\n");

    result = strlcat(dst1, " World", 8);
    printf("Original strlcat result: %s, Length: %zu\n", dst1, result);

    result = ft_strlcat(dst2, " World", 8);
    printf("ft_strlcat result: %s, Length: %zu\n\n", dst2, result);

    // Test 4: Empty dst
    strcpy(dst1, "");
    strcpy(dst2, "");
    printf("Test 4: Empty dst\n");

    result = strlcat(dst1, "World", sizeof(dst1));
    printf("Original strlcat result: %s, Length: %zu\n", dst1, result);

    result = ft_strlcat(dst2, "World", sizeof(dst2));
    printf("ft_strlcat result: %s, Length: %zu\n\n", dst2, result);

    // Test 5: Zero buffer size
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    printf("Test 5: Zero buffer size\n");

    result = strlcat(dst1, "World", 0);
    printf("Original strlcat result: %s, Length: %zu\n", dst1, result);

    result = ft_strlcat(dst2, "World", 0);
    printf("ft_strlcat result: %s, Length: %zu\n", dst2, result);

    return 0;
}*/