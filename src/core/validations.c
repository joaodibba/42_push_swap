				/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:00:39 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/14 18:05:38 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	compare(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

bool arguments_are_duplicated(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < ac - 1)
    {
        j = i + 1;
        while (j < ac)
        {
            if (ft_atoi(av[i]) == ft_atoi(av[j]))
                return (true);
            j++;
        }
        i++;
    }
    return (false);
}

#include <limits.h>

bool	arguments_are_within_integer_range(int ac, char **av)
{
    int i;

    i = 0;
    while (i < ac)
    {
		 if ((long_atoi(av[i]) > INT_MAX || long_atoi(av[i]) < INT_MIN))
		    return (false);
        i++;
    }
    return (true);
}

bool arguments_are_numbers(int ac, char **av)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '+' || av[i][j] == '-')
		{
			j++;
			if (av[i][j] == '\0')
				return (false);
		}
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	arguments_are_valid(int ac, char **av)
{
	if (arguments_are_numbers(ac, av) != true)
		return (false);
	if (arguments_are_within_integer_range(ac, av) == false)
		return (false);
	if (arguments_are_duplicated(ac, av) == true)
		return (false);
	return (true);
}