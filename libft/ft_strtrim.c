/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:24:35 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/24 13:07:15 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*res;
	size_t	end_idx;
	size_t	start_idx;
	size_t	i;

	if (!s)
		return (NULL);
	start_idx = 0;
	while (s[start_idx] && ft_strchr(set, s[start_idx]))
		start_idx++;
	if (!s[start_idx])
		return (ft_strdup(""));
	end_idx = ft_strlen(s) - 1;
	while (end_idx > start_idx && ft_strchr(set, s[end_idx]))
		end_idx--;
	res = (char *)malloc((end_idx - start_idx + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (start_idx <= end_idx)
	{
		res[i++] = s[start_idx++];
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *str = "abcHELLObca";
// 	printf("%s\n", ft_strtrim(str, "abc"));
// }