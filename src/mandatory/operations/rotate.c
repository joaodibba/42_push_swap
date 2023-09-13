/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:41:52 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/12 17:53:37 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

// [RA] ROTATE_A: shift up all elements of stack A by 1 (the first element becomes the last one).
void	rra(t_ship *ship_a)
{
	if (!ship_a->head || !ship_a->head->next || !ship_a->tail || ship_a->head == ship_a->tail)
		return;
	// Update the tail to point to the previous node
	ship_a->tail->next = ship_a->head;
	ship_a->head->prev = ship_a->tail;
	// Update the head and tail pointers
	ship_a->tail = ship_a->tail->prev;
	ship_a->head = ship_a->tail->next;
	// Break the circular link
	ship_a->tail->next = NULL;
	ship_a->head->prev = NULL;
	printf("rra\n");
}


	// if (!ship_a->head || !ship_a->head->next || !ship_a->tail || ship_a->head == ship_a->tail)
	// 	return;
// If there are 0 elements in the list (!ship_a->head)
// If there is only 1 element in the list (!ship_a->head->next)
// If the list is uninitialized (!ship_a->tail)
// If there is only 1 element in the list, and head is equal to tail (ship_a->head == ship_a->tail)

// [RB] ROTATE_B: shift up all elements of stack B by 1 (the first element becomes the last one).
void	rrb(t_ship *ship_b)
{
	if (!ship_b->head || !ship_b->head->next || !ship_b->tail || ship_b->head == ship_b->tail)
		return;
	ship_b->tail->next = ship_b->head;
	ship_b->head->prev = ship_b->tail;
	ship_b->tail = ship_b->tail->prev;
	ship_b->head = ship_b->tail->next;
	ship_b->tail->next = NULL;
	ship_b->head->prev = NULL;
	printf("rrb\n");
}

void	rr(t_shipyard *shipyard)
{
	ra(shipyard->ship_a);
	rb(shipyard->ship_b);
	printf("rrr\n");
}