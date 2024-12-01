/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:10:41 by alisseye          #+#    #+#             */
/*   Updated: 2024/12/02 16:17:21 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
