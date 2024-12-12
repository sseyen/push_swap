/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:08:47 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/12 19:06:24 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
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

void	move_to_b(t_list **stack_a, t_list **stack_b, int count)
{
	int	cheapest_index;

	while (count-- > 0)
	{
		cheapest_index = find_cheapest(*stack_a, *stack_b);
		rotate_to_top(stack_a, cheapest_index);
		pb(stack_a, stack_b);
	}
}

void	move_to_a(t_list **stack_a, t_list **stack_b, int count)
{
	int	target_index;

	while (count-- > 0)
	{
		target_index = find_correct_position(*stack_a, *stack_b);
		rotate_to_top(stack_a, target_index, 'a');
		pa(stack_a, stack_b);
	}
}
