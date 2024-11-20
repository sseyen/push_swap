/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:18:31 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 14:40:47 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

// #include <stdio.h>
// static void f(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = ft_toupper(*c);
// }
// int	main(void)
// {
// 	char str[] = "hello";
// 	ft_striteri(str, f);
// 	printf("%s\n", str);
// }