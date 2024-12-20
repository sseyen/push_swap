/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:08:47 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/20 20:26:05 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_avg(t_list *stack, int size)
{
	long long	sum;

	sum = 0;
	while (stack)
	{
		sum += *(int *)(stack->content);
		stack = stack->next;
	}
	return ((int)(sum / size));
}

void	*calculate_cost(t_list *stack_a, t_list *stack_b)
{
	t_move_cost *cost;

	cost = malloc(sizeof(t_move_cost));
	if (!cost)
		return (NULL);
}

t_move_cost	*get_cheapest(t_list *stack_a, t_list *stack_b)
{
	t_move_cost	*cheapest;
	t_move_cost	*tmp;

	cheapest = calculate_cost(stack_a, stack_b);
	if (!cheapest)
		return (NULL);
	while (stack_b)
	{
		tmp = calculate_cost(stack_a, stack_b);
		if (!tmp)
		{
			free(cheapest);
			return (NULL);
		}
		if (tmp->total < cheapest->total)
		{
			cheapest->value = tmp->value;
			cheapest->ra = tmp->ra;
			cheapest->rra = tmp->rra;
			cheapest->rb = tmp->rb;
			cheapest->rrb = tmp->rrb;
			cheapest->total = tmp->total;
		}
		stack_b = stack_b->next;
		free(tmp);
	}
	return (cheapest);
}

int	move_to_a(t_list **stack_a, t_list **stack_b)
{
	t_move_cost	*cheapest;

	while (*stack_b)
	{
		cheapest = get_cheapest(*stack_a, *stack_b);
		if (!cheapest)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		execute_moves(cheapest, stack_a, stack_b);
	}
	free(cheapest);
	return (0);
}

void	move_to_b(t_list **stack_a, t_list **stack_b, int size)
{
	int	avg;
	int	i;

	if (size <= 3)
		return ;
	avg = get_avg(*stack_a, size);
	i = size;
	while (i--)
	{
		if (*(int *)(*stack_a)->content < avg)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort(stack_a, stack_b, ft_lstsize(*stack_a));
}
