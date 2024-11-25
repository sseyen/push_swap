/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:29:11 by alisseye          #+#    #+#             */
/*   Updated: 2024/11/25 17:19:20 by alisseye         ###   ########.fr       */
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
	t_list	**stack;

	if (!validate_input(argc, argv) || argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack = get_stack(argc, argv);
	if (!stack)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	print_stack(stack);
	ft_lstclear(stack, free);
	free(stack);
	return (0);
}
