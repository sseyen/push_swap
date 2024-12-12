/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:22:05 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/12 18:37:51 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	if (!stack || !stack->next)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 1 || size == 0 || is_sorted(*stack_a))
		return ;
	if (size == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		move_to_a(stack_a, stack_b, 1);
	}
	else
	{
		move_to_b(stack_a, stack_b, size - 3);
		sort_three(stack_a);
		move_to_a(stack_a, stack_b, size - 3);
	}
	free_stacks(stack_a, stack_b);
}
