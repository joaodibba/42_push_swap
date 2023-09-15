/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:38:25 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/15 01:25:06 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

int	find_smallest_index(t_ship *ship)
{
	t_container	*smallest;
	t_container	*current;

	smallest = ship->head;
	current = ship->head;
	while (current != NULL)
	{
		if (current->value < smallest->value)
			smallest = current;
		current = current->next;
	}
	return (smallest->index);
}

void index_rec(t_container *head, int i)
{
	if (!head)
		return ;
	head->index = i;
	index_rec(head->next, i + 1);
}

void	sort_five(t_shipyard *shipyard)
{
	int	smallest_index;
	int	smallest_value;
	int	i;

	i = 2;
	while (i)
	{
		index_rec(shipyard->ship_a->head, 0);
		smallest_value = find_smallest(shipyard->ship_a);
		smallest_index = find_smallest_index(shipyard->ship_a);
		if (smallest_index <= i)
			while (shipyard->ship_a->head->value != smallest_value)
				ra(shipyard->ship_a);
		else
			while (shipyard->ship_a->head->value != smallest_value)
				rra(shipyard->ship_a);	
		pb(shipyard);
		i--;
	}
	if (!is_sorted(shipyard->ship_a))
		sort_three(shipyard);
	pa(shipyard);
	pa(shipyard);
}
