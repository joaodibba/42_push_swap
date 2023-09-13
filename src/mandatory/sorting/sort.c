/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:24:40 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/12 22:26:58 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	list_size(t_container *head)
{
	if (!head)
		return (0);
	return (1 + list_size(head->next));
}

bool	is_sorted(t_ship *ship)
{
	t_container *current;

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
	int	listsize;
	bool sorted;

	sorted = is_sorted(shipyard->ship_a);
	listsize = list_size(shipyard->ship_a->head);
	if (listsize <= 3 && !sorted)
		sort_three(shipyard);
	else if (listsize <= 5 && !sorted)
		sort_five(shipyard);
	else if (listsize > 5 && !sorted)
		radix(shipyard);
}