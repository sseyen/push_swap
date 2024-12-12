/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:07:16 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/12 19:19:36 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_a_moves(t_list *stack_a, int index)
{
	int	size;

	size = ft_lstsize(stack_a);
	if (index <= size / 2)
		return (index);
	return (size - index);
}

int	calculate_b_moves(t_list *stack_b, int value)
{
	int		size;
	int		index;
	int		current_value;
	int		next_value;
	t_list	*current;

	size = ft_lstsize(stack_b);
	index = 0;
	current = stack_b;
	while (current)
	{
		current_value = *(int *)(current->content);
		next_value = current->next ? *(int *)(current->next->content) : *(int *)(stack_b->content);
		if ((value > current_value && value < next_value) || \
			(current_value > next_value && \
			(value > current_value || value < next_value)))
			break ;
		current = current->next;
		index++;
	}
	if (index <= size / 2)
		return (index);
	return (size - index);
}

int	calculate_cost(t_list *stack_a, t_list *stack_b, int index)
{
	int	a_moves;
	int	b_moves;

	a_moves = calculate_a_moves(stack_a, index);
	b_moves = calculate_b_moves(stack_b, *(int *)(stack_a->content));
	return (a_moves + b_moves);
}

int	find_cheapest(t_list *stack_a, t_list *stack_b)
{
	int	cost;
	int	min_cost;
	int	cheapest_index;
	int	index;

	min_cost = *(int *)stack_a->content;
	cheapest_index = 0;
	index = 0;
	while (stack_a)
	{
		cost = calculate_cost(stack_a, stack_b, index);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_index = index;
		}
		stack_a = stack_a->next;
		index++;
	}
	return (cheapest_index);
}
