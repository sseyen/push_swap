/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:12:13 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 15:25:05 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
}

// #include <stdio.h>
// int main(void)
// {
// 	const char *str = "Hello, world!";
// 	const char *s = ft_strrchr(str, '\0');
// 	printf("Original: %s\n", str);
// 	printf("Link: %s\n", s);
// 	return (0);
// }