/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:04:48 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/14 23:58:12 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	init(int ac, char **av, t_shipyard *shipyard)
{
	shipyard->ship_a = (t_ship *)malloc(sizeof(t_ship));
	shipyard->ship_b = (t_ship *)malloc(sizeof(t_ship));
	if (!shipyard->ship_b || !shipyard->ship_a)
		return (1);
	shipyard->ship_a->head = NULL;
	shipyard->ship_a->tail = NULL;
	shipyard->ship_b->head = NULL;
	shipyard->ship_b->tail = NULL;
	create_stack(ac, av, shipyard);
	if (!shipyard->ship_a->head)
		return (1);
	return (0);
}

int	push_swap(t_shipyard *shipyard, char **av, int flag)
{
	sort(shipyard);
	free_all(shipyard, av, flag);
	return (0);
}

int	main(int ac, char **av)
{
	t_shipyard	shipyard;

	av++;
	if (ac == 2)
	{
		av = ft_split(*av, ' ');
		ac = doublearraysize(av);
		if (arguments_are_valid(ac, av) && !init(ac, av, &shipyard))
			return (push_swap(&shipyard, av, 1));
		free_all(&shipyard, av, 1);
		ft_putstr_fd("Error\n", STDERR);
		return (1);
	}
	if (ac-- > 1 && arguments_are_valid(ac, av) && !init(ac, av, &shipyard))
		return (push_swap(&shipyard, av, 0));
	free_all(&shipyard, av, 0);
	ft_putstr_fd("Error\n", STDERR);
	return (1);
}