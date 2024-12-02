/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:10:22 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/02 20:22:15 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine_chunk_count(int size)
{
	int	chunk_count;
	int	sqrt;

	if (size <= 100)
	{
		sqrt = 1;
		while (sqrt * sqrt < size)
			sqrt++;
		chunk_count = sqrt;
	}
	else if (size <= 500)
		chunk_count = ft_ceil(ft_log2(size) * 1.2);
	else
		chunk_count = size / 50;
	return (chunk_count);
}

void	chunk_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk_count;
	int	chunk_size;

	chunk_count = determine_chunk_count(ft_lstsize(*stack_a));
	chunk_size = size / chunk_count;
}
