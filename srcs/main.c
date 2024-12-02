/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:29:11 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/02 17:27:42 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_putnbr_fd(*(int *)tmp->content, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}

static t_list	**get_stack(int argc, char **argv)
{
	t_list	**stack;
	t_list	*new_node;
	int		i;

	stack = malloc(sizeof(t_list *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	i = argc - 1;
	while (i > 0)
	{
		new_node = get_new_node(ft_atoi(argv[i]));
		if (!new_node)
		{
			ft_lstclear(stack, NULL);
			free(stack);
			return (NULL);
		}
		ft_lstadd_front(stack, new_node);
		i--;
	}
	return (stack);
}

static int	validate_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		j = 0;
		while (j < i)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1 || !validate_input(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = get_stack(argc, argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_b = malloc(sizeof(t_list *));
	if (!stack_b)
	{
		ft_lstclear(stack_a, free);
		free(stack_a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	push_swap(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
