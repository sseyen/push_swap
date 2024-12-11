/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:30:15 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/11 01:00:53 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

// push_swap
void	push_swap(t_list **stack_a, t_list **stack_b);

// Sort algorithms
void	sort_three(t_list **stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);

// Utils
t_list	*get_new_node(int content);
void	free_stacks(t_list **a, t_list **b);
void	free_tab(char **split);
int		get_size(char **argv);
char	**copy_args(int argc, char **argv);

// Operations
void	push(t_list **dst, t_list **src);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	double_func(void (*f)(t_list **), t_list **a, t_list **b);

// Operations interface
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif