/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:24:40 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:55:12 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_size(t_container *head)
{
	if (!head)
		return (0);
	return (1 + stack_size(head->next));
}

bool	is_sorted(t_ship *ship)
{
	t_container	*current;

	if (!ship->head)
		return (true);
	current = ship->head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	sort(t_shipyard *shipyard)
{
	int	stacksize;

	stacksize = stack_size(shipyard->ship_a->head);
	if (stacksize <= 3 && !is_sorted(shipyard->ship_a))
		sort_three(shipyard);
	else if (stacksize <= 5 && !is_sorted(shipyard->ship_a))
		sort_five(shipyard);
	else if (stacksize > 5 && !is_sorted(shipyard->ship_a))
		radix(shipyard);
}
