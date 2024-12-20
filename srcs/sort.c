/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:08:47 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/20 18:53:45 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
