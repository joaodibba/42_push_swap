/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:22:39 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:50:39 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	add_index(t_ship *ship)
{
	t_container	*current;
	t_container	*compare;
	int			index;

	current = ship->head;
	compare = ship->head;
	while (current)
	{
		index = 0;
		compare = ship->head;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	find_max_bits(t_ship *ship)
{
	int	stacksize;
	int	max_bits;

	max_bits = 1;
	stacksize = stack_size(ship->head);
	while ((stacksize - 1) >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_shipyard *shipyard)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	i = 0;
	size = stack_size(shipyard->ship_a->head);
	max_bits = find_max_bits(shipyard->ship_a);
	add_index(shipyard->ship_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((shipyard->ship_a->head->index >> i) & 1)
				ra(shipyard->ship_a);
			else
				pb(shipyard);
			j++;
		}
		while (shipyard->ship_b->head)
			pa(shipyard);
		i++;
	}
}
