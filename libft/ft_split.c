/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:09:42 by alisseye          #+#    #+#             */
/*   Updated: 2024/09/27 21:40:17 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			counter++;
			while (*s && *s != c)
				s++;
		}
	}
	return (counter);
}

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_free_all(char **tab, int i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		wordlen;

	tab = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			wordlen = ft_wordlen(s, c);
			tab[i] = ft_substr(s, 0, wordlen);
			if (!tab[i])
				return (ft_free_all(tab, i));
			s += wordlen;
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*words = " word1     word2    word3    ";
// 	char **tab;
// 	int	i;
// 	tab = ft_split(words, ' ');
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	while (--i >= 0)
// 		free(tab[i]);
// }
