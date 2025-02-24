/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:05 by alisseye          #+#    #+#             */
/*   Updated: 2025/02/24 14:53:35 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack_a)->content;
	second = *(int *)(*stack_a)->next->content;
	third = *(int *)(*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && first > third && second < third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && first > third)
		rra(stack_a);
}

static void	sort_two(t_list **stack_a)
{
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a);
}

int	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 1 || size == 0 || is_sorted(*stack_a))
	{
		free_stacks(stack_a, stack_b);
		return (0);
	}
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		move_to_b(stack_a, stack_b);
		if (!is_sorted(*stack_a))
			sort_three(stack_a);
		if (move_to_a(stack_a, stack_b) == 1)
		{
			free_stacks(stack_a, stack_b);
			return (1);
		}
	}
	free_stacks(stack_a, stack_b);
	return (0);
}
