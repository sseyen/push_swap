/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:45 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/24 13:05:25 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>
#include <strings.h>
int main(void)
{
    char buffer1[20] = "Hello, World!";
    char buffer2[20] = "Hello, World!";

	printf("Before bzero: \"%s\"\n", buffer1);
    bzero(buffer1, 5);
    printf("After bzero: \"%s\"\n", buffer1);

	printf("Before bzero: \"%s\"\n", buffer2);
    ft_bzero(buffer2, 5);
    printf("After ft_bzero: \"%s\"\n", buffer2);

    return 0;
}*/