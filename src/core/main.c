/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:04:48 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:51:14 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	init(int ac, char **av, t_shipyard *shipyard)
{
	shipyard->ship_a = (t_ship *)malloc(sizeof(t_ship));
	shipyard->ship_b = (t_ship *)malloc(sizeof(t_ship));
	if (!shipyard->ship_b || !shipyard->ship_a)
		return (1);
	if (!shipyard->ship_a)
	{
		ft_printf("Error [MEMORY ALLOCATION FAILED].\n"); //
		return (1);
	}
	shipyard->ship_a->head = NULL;
	shipyard->ship_a->tail = NULL;
	shipyard->ship_b->head = NULL;
	shipyard->ship_b->tail = NULL;
	create_stack(ac, av, shipyard);
	if (!shipyard->ship_a->head)
	{
		ft_printf("Error [EMPTY LIST].\n"); //
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_shipyard	shipyard;

	if (!arguments_are_valid(ac, av))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (init(ac, av, &shipyard))
	{
		ft_printf("Error\n");
		return (1);
	}
	sort(&shipyard);
	free_stack(shipyard.ship_a);
	return (0);
}
