/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:31:37 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/02 16:03:07 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

// left rotate
// 1 2 3 4 5
// 2 3 4 5 1
void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

// right rotate
// 1 2 3 4 5
// 5 1 2 3 4
void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	double_func(void (*f)(t_list **), t_list **a, t_list **b)
{
	f(a);
	f(b);
}
