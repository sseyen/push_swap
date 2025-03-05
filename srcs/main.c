/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:29:11 by alisseye          #+#    #+#             */
/*   Updated: 2025/03/05 20:19:37 by alisseye         ###   ########.fr       */
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
