/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:24:00 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 14:48:50 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// if(size!=0 && nmemb > ((size_t)-1)/nmemb) 
// return NULL;
// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
//     int *arr;
//     size_t count = 5;
// 	size_t i = 0;
//     arr = (int *)ft_calloc(count, sizeof(int));
//     if (!arr)
//     {
//         printf("Memory allocation failed.\n");
//         return 1;
//     }
// 	while (i < count)
// 	{
// 		printf("arr[%zu] = %d\n", i, arr[i]);
// 		i++;
// 	}
//     free(arr);
//     return 0;
// }