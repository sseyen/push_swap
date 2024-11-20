/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:27:33 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 14:35:50 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// static void	del(void *content);
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str1 = "first";
// 	t_list	*node = ft_lstnew(str1);
// 	t_list	**lst = &node;
// 	char	*str2 = "second";
// 	t_list	*new_node = ft_lstnew(str2);
// 	ft_lstadd_front(lst, new_node);
// 	t_list	*temp = *lst;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	ft_lstclear(lst, del);
// }