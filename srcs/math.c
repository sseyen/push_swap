/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:08:04 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/02 20:09:30 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_log2(double n)
{
	int	res;

	res = 0;
	while (n > 1)
	{
		n /= 2;
		res++;
	}
	return (res);
}

int	ft_ceil(double n)
{
	int	res;

	res = (int)n;
	if (n > res)
		res++;
	return (res);
}
