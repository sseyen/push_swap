/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:19:15 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 14:34:16 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') \
	|| (c >= 'a' && c <= 'z') \
	|| (c >= '0' && c <= '9'));
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_isalnum('#'));
// }