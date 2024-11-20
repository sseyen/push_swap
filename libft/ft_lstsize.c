/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:50:57 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/26 14:36:49 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
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
// 	printf("%d\n", ft_lstsize(*lst));
// 	ft_lstclear(lst, del);
// }