/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:36 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 02:21:56 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	pb(t_shipyard *shipyard)
{
	push(shipyard->ship_a->head->value, shipyard->ship_a->head->index, shipyard->ship_b);
	pop(shipyard->ship_a);
	printf("pb\n");
}

void	pa(t_shipyard *shipyard)
{
	push(shipyard->ship_b->head->value, shipyard->ship_b->head->index, shipyard->ship_a);
	pop(shipyard->ship_b);
	printf("pa\n");
}