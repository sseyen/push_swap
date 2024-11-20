/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:20:42 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 14:35:33 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

// static void	del(void *content);
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str1 = "first";
// 	t_list	*node1 = ft_lstnew(str1);
// 	t_list	**lst = &node1;
// 	char	*str2 = "second";
// 	t_list	*node2 = ft_lstnew(str2);
// 	ft_lstadd_front(lst, node2);
// 	char	*str3 = "third";
// 	t_list	*node3 = ft_lstnew(str3);
// 	ft_lstadd_back(lst, node3);
// 	t_list	*temp = *lst;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	ft_lstclear(lst, del);
// }