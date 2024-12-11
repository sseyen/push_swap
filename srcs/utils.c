/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:10:41 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/04 14:16:31 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**copy_args(int argc, char **argv)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * argc);
	if (!args)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		args[i] = ft_strdup(argv[i + 1]);
		if (!args[i])
		{
			free_tab(args);
			return (NULL);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}

void	free_stacks(t_list **a, t_list **b)
{
	ft_lstclear(a, free);
	free(a);
	ft_lstclear(b, free);
	free(b);
}

t_list	*get_new_node(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = malloc(sizeof(int));
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}
	*(int *)new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
