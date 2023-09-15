/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:41:28 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/15 02:16:24 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// [RRA] REVERSE_ROTATE_A: shift down all elements of stack A by 1 
// (the last element becomes the first one).
void	rra(t_ship *ship_a)
{
	if (!ship_a->head || !ship_a->head->next || \
	!ship_a->tail || ship_a->head == ship_a->tail)
		return ;
	ship_a->tail->next = ship_a->head;
	ship_a->head->prev = ship_a->tail;
	ship_a->tail = ship_a->tail->prev;
	ship_a->head = ship_a->tail->next;
	ship_a->tail->next = NULL;
	ship_a->head->prev = NULL;
	ft_printf("rra\n");
}

// [RRB] REVERSE_ROTATE_B: shift down all elements of stack B by 1 
// (the last element becomes the first one).
void	rrb(t_ship *ship_b)
{
	if (!ship_b->head || !ship_b->head->next || \
	!ship_b->tail || ship_b->head == ship_b->tail)
		return ;
	ship_b->tail->next = ship_b->head;
	ship_b->head->prev = ship_b->tail;
	ship_b->tail = ship_b->tail->prev;
	ship_b->head = ship_b->tail->next;
	ship_b->tail->next = NULL;
	ship_b->head->prev = NULL;
	ft_printf("rrb\n");
}

// void	rrr(t_shipyard *shipyard)
// {
// 	rra(shipyard->ship_a);
// 	rrb(shipyard->ship_b);
// 	ft_printf("rrr\n");
// }