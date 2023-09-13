/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:38:25 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 20:43:40 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	find_smallest(t_ship *ship)
{
	int			smallest;
	t_container	*current;

	smallest = ship->head->value;
	current = ship->head;
	while (current != NULL)
	{
		if (current->value < smallest)
			smallest = current->value;
		current = current->next;
	}

	return (smallest);
}

void	sort_five(t_shipyard *shipyard)
{
	int	smallest;

	smallest = find_smallest(shipyard->ship_a);
	while (shipyard->ship_a->head->value != smallest)
		rra(shipyard->ship_a);
	pb(shipyard);
	smallest = find_smallest(shipyard->ship_a);
	while (shipyard->ship_a->head->value != smallest)
		rra(shipyard->ship_a);
	pb(shipyard);
	if (!is_sorted(shipyard->ship_a))
		sort_three(shipyard);
	pa(shipyard);
	pa(shipyard);
}
