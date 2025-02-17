/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:29:11 by alisseye          #+#    #+#             */
/*   Updated: 2025/02/11 23:08:22 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**get_stack(int argc, char **args)
{
	t_list	**stack;
	t_list	*new_node;
	int		i;

	stack = malloc(sizeof(t_list *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	i = argc - 1;
	while (i >= 0)
	{
		new_node = get_new_node(ft_atoi(args[i]));
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

static int	init_stacks(t_list ***a, t_list ***b, int argc, char **args)
{
	*a = get_stack(argc, args);
	if (!(*a))
		return (0);
	*b = malloc(sizeof(t_list *));
	if (!(*b))
	{
		ft_lstclear(*a, NULL);
		free(*a);
		return (0);
	}
	return (1);
}

static int	validate_input(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] == '-' || args[i][j] == '+'))
				j++;
			if (!ft_isdigit(args[i][j])) // INT_MIN <= arg <= INT_MAX
				return (0);
			j++;
		}
		j = 0;
		while (j < i)
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**get_args(int argc, char **argv)
{
	char	**args;

	if (argc == 1)
		return (NULL);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = copy_args(argc, argv);
	return (args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**args;
	int		args_count;

	args = get_args(argc, argv);
	args_count = 0;
	while (args && args[args_count])
		args_count++;
	if (!args || !validate_input(args_count, args))
	{
		free_tab(args);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = NULL;
	stack_b = NULL;
	if (!init_stacks(&stack_a, &stack_b, args_count, args)) // without 3rd*, then without &
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	free_tab(args);
	return (push_swap(stack_a, stack_b));
}
