/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:50:12 by alisseye          #+#    #+#             */
/*   Updated: 2025/03/02 14:02:51 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_list **stack_a)
{
	int		i;
	int		min;
	int		size;
	t_list	*tmp;

	i = 0;
	tmp = *stack_a;
	min = ft_lstmin(tmp);
	size = ft_lstsize(tmp);
	while (*(int *)tmp->content != min)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < size / 2)
		while (i-- > 0)
			ra(stack_a);
	else
		while (size - i++ > 0)
			rra(stack_a);
}

int	is_sorted(t_list *stack)
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

int	contain_smaller(t_list *stack, int value)
{
	while (stack)
	{
		if (*(int *)stack->content < value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

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

t_move_cost	*get_cheapest(t_list *stack_a, t_list *stack_b, int size)
{
	t_move_cost	*cheapest;
	t_move_cost	*tmp;
	t_list		*tmp_b;

	tmp_b = stack_b;
	cheapest = calculate_cost(stack_a, stack_b, *(int *)tmp_b->content, size);
	if (!cheapest)
		return (NULL);
	if (cheapest->total == 0)
		return (cheapest);
	while (tmp_b && cheapest->total > 5 + size / 100)
	{
		tmp = calculate_cost(stack_a, stack_b, *(int *)tmp_b->content, size);
		if (!tmp)
			return (free(cheapest), NULL);
		if (tmp->total < cheapest->total)
		{
			free(cheapest);
			cheapest = tmp;
		}
		else
			free(tmp);
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}
