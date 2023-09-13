/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:38:19 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:22:51 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	sort_three(t_shipyard *shipyard)
{
	if (stack_size(shipyard->ship_a->head) == 2)
		sa(shipyard->ship_a);
	while (!is_sorted(shipyard->ship_a))
	{
		if (shipyard->ship_a->head->value > \
		shipyard->ship_a->head->next->value && \
		shipyard->ship_a->head->value > \
		shipyard->ship_a->head->next->next->value)
			ra(shipyard->ship_a);
		if (shipyard->ship_a->head->value < \
		shipyard->ship_a->head->next->value && \
		shipyard->ship_a->head->next->value > \
		shipyard->ship_a->head->next->next->value)
			rra(shipyard->ship_a);
		if (shipyard->ship_a->head->value > shipyard->ship_a->head->next->value)
			sa(shipyard->ship_a);
	}
}