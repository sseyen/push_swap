/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:29:11 by alisseye          #+#    #+#             */
/*   Updated: 2025/03/01 18:33:05 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*init_stack(int argc, char **args)
{
	t_list	*stack;
	t_list	*new_node;
	int		i;

	stack = NULL;
	i = argc - 1;
	while (i >= 0)
	{
		new_node = get_new_node(ft_atoi(args[i]));
		if (!new_node)
		{
			ft_lstclear(&stack, NULL);
			return (NULL);
		}
		ft_lstadd_front(&stack, new_node);
		i--;
	}
	return (stack);
}

static int	is_int(int n)
{
	return (n >= INT_MIN && n <= INT_MAX);
}

static int	validate_input(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc && is_int(ft_atoi(args[i])))
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] == '-' || args[i][j] == '+'))
				j++;
			if (!ft_isdigit(args[i][j]))
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
	t_list	*stack_a;
	t_list	*stack_b;
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
	stack_a = init_stack(args_count, args);
	if (!stack_a)
	{
		free_tab(args);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_b = NULL;
	free_tab(args);
	return (push_swap(&stack_a, &stack_b));
}
