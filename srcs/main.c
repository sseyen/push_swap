/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:29:11 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/20 16:25:28 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*args_to_stack(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = argc - 1;
	stack->stack = malloc(sizeof(int) * stack->size);
	if (!stack->stack)
	{
		free(stack);
		return (NULL);
	}
	i = 1;
	while (i < argc)
	{
		stack->stack[i - 1] = ft_atoi(argv[i]);
		i++;
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
	t_stack	*stack;

	if (!validate_input(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack = args_to_stack(argc, argv);
	if (!stack)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	// push_swap(stack);
	return (0);
}
