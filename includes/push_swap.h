/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:30:15 by alisseye          #+#    #+#             */
/*   Updated: 2025/02/17 13:33:04 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_move_cost
{
	int	value;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	total;
}	t_move_cost;

// push_swap
int			push_swap(t_list **stack_a, t_list **stack_b);

// Sort algorithms
void		move_to_b(t_list **stack_a, t_list **stack_b);
int			move_to_a(t_list **stack_a, t_list **stack_b);

// Calculate moves
t_move_cost	*calculate_cost(t_list *stack_a, t_list *stack_b, \
							int value, int size);

// Utils
int			is_int(int n);
t_list		*get_new_node(int content);
void		free_stacks(t_list **a, t_list **b);
void		free_tab(char **split);
int			get_size(char **argv);
char		**copy_args(int argc, char **argv);

// Utils sort
void		move_to_top(t_list **stack_a);
int			is_sorted(t_list *stack);
int			contain_smaller(t_list *stack, int value);
int			get_avg(t_list *stack, int size);
t_move_cost	*get_cheapest(t_list *stack_a, t_list *stack_b, int size);

// Utils moves
void		copy_moves_data(t_move_cost	*dest, t_move_cost *src);
int			get_min(int a, int b, int c, int d);
int			ft_max(int a, int b);
int			ft_lstmin(t_list *stack);
int			ft_lstmax(t_list *stack);

// Operations
void		push(t_list **dst, t_list **src);
void		swap(t_list **stack);
void		rotate(t_list **stack);
void		reverse_rotate(t_list **stack);
void		double_func(void (*f)(t_list **), t_list **a, t_list **b);

// Operations interface
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);

#endif