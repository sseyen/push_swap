/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:28:02 by alisseye          #+#    #+#             */
/*   Updated: 2025/02/24 15:19:30 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_moves_data(t_move_cost	*dest, t_move_cost *src)
{
	dest->value = src->value;
	dest->ra = src->ra;
	dest->rra = src->rra;
	dest->rb = src->rb;
	dest->rrb = src->rrb;
	dest->total = src->total;
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_min(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}

int	ft_lstmin(t_list *stack)
{
	int	min;

	min = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < min)
			min = *(int *)stack->content;
		stack = stack->next;
	}
	return (min);
}

int	ft_lstmax(t_list *stack)
{
	int	max;

	max = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > max)
			max = *(int *)stack->content;
		stack = stack->next;
	}
	return (max);
}
