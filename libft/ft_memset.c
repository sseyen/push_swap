/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:19:38 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 14:45:21 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (n--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (b);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
    char buffer1[20] = "Hello, World!";
    char buffer2[20] = "Hello, World!";

    printf("Before memset:\n");
    printf("Original: %s\n", buffer1);
    printf("Custom: %s\n\n", buffer2);

    memset(buffer1, '*', 5);
    ft_memset(buffer2, '*', 5);

    printf("After memset:\n");
    printf("Original: %s\n", buffer1);
    printf("Custom: %s\n", buffer2);

    return 0;
}*/
