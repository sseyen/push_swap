/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisseye <alisseye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:18:34 by alisseye          #+#    #+#             */
/*   Updated: 2025/03/05 20:29:17 by alisseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	long	sign;
	long	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static int	only_ints(int argc, char **args)
{
	while (argc--)
		if (ft_atol(args[argc]) > INT_MAX || ft_atol(args[argc]) < INT_MIN)
			return (0);
	return (1);
}

int	no_duplicates(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(args[j]) == ft_atoi(args[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_input(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (args[i][j])
		{
			if (j == 0 && (args[i][j] == '-' || args[i][j] == '+'))
				j++;
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!only_ints(argc, args))
	return (0);
	if (!no_duplicates(argc, args))
		return (0);
	return (1);
}
