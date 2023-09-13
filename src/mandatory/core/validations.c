/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:00:39 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:25:35 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

bool	arguments_are_duplicated(int ac, char **av)
{
	int		i;
	int		j;
	bool	duplicate_found;

	i = 1;
	j = 0;
	duplicate_found = false;
	while (i < ac - 1 && !duplicate_found)
	{
		j = i + 1;
		while (j < ac && !duplicate_found)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				duplicate_found = true;
				ft_printf("AV[%d] ", i);
				ft_printf("AND AV[%d] ARE THE SAME\n", j);
			}
			j++;
		}
		i++;
	}
	return (duplicate_found);
}

bool	arguments_are_within_integer_range(char *av)
{
	if ((av[0] == '-' && (ft_strlen(av) > 11 || \
		(ft_strlen(av) == 11 && ft_strcmp(av, "-2147483648") > 0))) || \
		(av[0] != '-' && (ft_strlen(av) > 10 || \
		(ft_strlen(av) == 10 && ft_strcmp(av, "2147483647") > 0))))
		return (false);
	return (true);
}

bool	arguments_are_numbers(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (av[i] == '\0')
		return (false);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	arguments_are_valid(int ac, char **av)
{
	if (arguments_are_duplicated(ac, av) == true)
	{
		ft_printf("Error [DUPLICATES].\n");
		return (false);
	}
	while (ac-- > 1)
	{
		if (arguments_are_numbers(av[ac]) != true)
		{
			ft_printf("Error [NOT A NUMBER].\n");
			return (false);
		}
		if (arguments_are_within_integer_range(av[ac]) != true)
		{
			ft_printf("Error [NOT A INTEGER].\n");
			return (false);
		}
	}
	return (true);
}