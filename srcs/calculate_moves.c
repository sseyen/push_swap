/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:31:13 by alisseye          #+#    #+#             */
/*   Updated: 2025/02/17 12:36:34 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_b_moves(t_list *stack_b, int value, t_move_cost *cost, int size)
{
	cost->rb = 0;
	cost->rrb = size;
	while (stack_b && value != *(int *)stack_b->content)
	{
		stack_b = stack_b->next;
		cost->rb++;
	}
	cost->rrb = cost->rrb - cost->rb;
}

static void	get_a_moves(t_list *stack_a, int value, t_move_cost *cost)
{
	int	min;
	int	max;
	int	size;

	min = ft_lstmin(stack_a);
	max = ft_lstmax(stack_a);
	size = ft_lstsize(stack_a);
	cost->ra = 0;
	cost->rra = ft_lstsize(stack_a);
	while (stack_a && stack_a->next)
	{
		cost->ra++;
		if (value > *(int *)stack_a->content \
			&& value < *(int *)stack_a->next->content)
			break ;
		if (*(int *)stack_a->content == max && value > max)
			break ;
		if (ft_lstsize(stack_a) != size && stack_a->next)
			if (*(int *)stack_a->next->content == min && value < min)
				break ;
		stack_a = stack_a->next;
	}
	cost->rra = cost->rra - cost->ra;
	if (!stack_a->next)
		cost->ra = 0;
}

static void	determine_moves(t_move_cost *cost, int ra_rrb, int rra_rb)
{
	int	min;

	min = get_min(ra_rrb, rra_rb, \
		ft_max(cost->ra, cost->rb), ft_max(cost->rra, cost->rrb));
	if (min == ra_rrb)
	{
		cost->rra = 0;
		cost->rb = 0;
	}
	else if (min == rra_rb)
	{
		cost->ra = 0;
		cost->rrb = 0;
	}
	else if (min == ft_max(cost->ra, cost->rb))
	{
		cost->rra = 0;
		cost->rrb = 0;
	}
	else
	{
		cost->ra = 0;
		cost->rb = 0;
	}
	cost->total = min;
}

static void	get_total_moves(t_move_cost *cost)
{
	int	ra_rrb;
	int	rra_rb;

	ra_rrb = cost->ra + cost->rrb;
	rra_rb = cost->rra + cost->rb;
	determine_moves(cost, ra_rrb, rra_rb);
}

t_move_cost	*calculate_cost(t_list *stack_a, t_list *stack_b, \
							int value, int size)
{
	t_move_cost	*cost;

	cost = malloc(sizeof(t_move_cost));
	if (!cost)
		return (NULL);
	cost->value = value;
	cost->ra = 0;
	cost->rra = 0;
	cost->rb = 0;
	cost->rrb = 0;
	cost->total = 0;
	get_b_moves(stack_b, value, cost, size);
	get_a_moves(stack_a, value, cost);
	get_total_moves(cost);
	return (cost);
}
