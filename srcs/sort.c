/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:08:47 by alisseye          #+#    #+#             */
/*   Updated: 2025/02/24 15:26:33 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_moves(t_move_cost *cheapest, \
						t_list **stack_a, t_list **stack_b)
{
	while (cheapest->ra > 0 && cheapest->rb > 0)
	{
		rr(stack_a, stack_b);
		cheapest->ra--;
		cheapest->rb--;
	}
	while (cheapest->ra-- > 0)
		ra(stack_a);
	while (cheapest->rb-- > 0)
		rb(stack_b);
	while (cheapest->rra > 0 && cheapest->rrb > 0)
	{
		rrr(stack_a, stack_b);
		cheapest->rra--;
		cheapest->rrb--;
	}
	while (cheapest->rra-- > 0)
		rra(stack_a);
	while (cheapest->rrb-- > 0)
		rrb(stack_b);
	pa(stack_a, stack_b);
}

int	move_to_a(t_list **stack_a, t_list **stack_b)
{
	t_move_cost	*cheapest;

	while (*stack_b)
	{
		cheapest = get_cheapest(*stack_a, *stack_b, ft_lstsize(*stack_b));
		if (!cheapest)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		execute_moves(cheapest, stack_a, stack_b);
		free(cheapest);
	}
	move_to_top(stack_a);
	return (0);
}

void	move_to_b(t_list **stack_a, t_list **stack_b)
{
	int	avg;
	int	i;

	while (stack_a && *stack_a && ft_lstsize(*stack_a) > 3 \
		&& !is_sorted(*stack_a))
	{
		avg = get_avg(*stack_a, ft_lstsize(*stack_a));
		i = ft_lstsize(*stack_a);
		while (i-- && ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a) \
			&& contain_smaller(*stack_a, avg))
		{
			if (*(int *)(*stack_a)->content < avg)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
}
