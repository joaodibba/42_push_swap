/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:41:52 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:54:36 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// [RA] ROTATE_A: shift up all elements of stack A by 1 (the first element becomes the last one).
void	ra(t_ship *ship_a)
{
	if (!ship_a->head || !ship_a->head->next || \
	!ship_a->tail || ship_a->head == ship_a->tail)
		return ;
	// Update the head to point to the next node
	ship_a->head->prev = ship_a->tail;
	ship_a->tail->next = ship_a->head;
	// Update the tail and head pointers
	ship_a->tail = ship_a->head;
	ship_a->head = ship_a->head->next;
	// Break the circular link
	ship_a->tail->next = NULL;
	ship_a->head->prev = NULL;
	printf("ra\n");
}

// [RB] ROTATE_B: shift up all elements of stack B by 1 (the first element becomes the last one).
void	rb(t_ship *ship_b)
{
	if (!ship_b->head || !ship_b->head->next || \
	!ship_b->tail || ship_b->head == ship_b->tail)
		return ;
	ship_b->head->prev = ship_b->tail;
	ship_b->tail->next = ship_b->head;
	ship_b->tail = ship_b->head;
	ship_b->head = ship_b->head->next;
	ship_b->tail->next = NULL;
	ship_b->head->prev = NULL;
	printf("rb\n");
}

void	rrr(t_shipyard *shipyard)
{
	rra(shipyard->ship_a);
	rrb(shipyard->ship_b);
	printf("rrr\n");
}
