/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:02:28 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 15:01:12 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

//static void	del(void *content);
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str1 = "first";
// 	t_list	*node = ft_lstnew(str1);
// 	t_list	**lst = &node;
// 	char	*str2 = "second";
// 	t_list	*new_node = ft_lstnew(str2);
// 	ft_lstadd_front(lst, new_node);
// 	printf("%s\n", (char *)ft_lstlast(*lst)->content);
// 	ft_lstclear(lst, del);
// }