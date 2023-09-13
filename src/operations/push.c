/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:40:36 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 22:09:02 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(int value,	int index, t_ship *ship)
{
	t_container	*new_node;

	new_node = (t_container *)malloc(sizeof(t_container));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->index = index;
	new_node->prev = NULL;
	if (ship->head != NULL)
	{
		new_node->next = ship->head;
		ship->head->prev = new_node;
		ship->head = new_node;
	}
	else
	{
		new_node->next = NULL;
		ship->head = new_node;
		ship->tail = new_node;
	}
}

void	pop(t_ship *ship)
{
	t_container	*temp;

	if (ship->head == NULL)
		return ;
	temp = ship->head;
	if (ship->head->next != NULL)
	{
		ship->head = ship->head->next;
		ship->head->prev = NULL;
	}
	else
		ship->head = NULL;
	free(temp);
}

void	pb(t_shipyard *shipyard)
{
	push(shipyard->ship_a->head->value, \
	shipyard->ship_a->head->index, shipyard->ship_b);
	pop(shipyard->ship_a);
	ft_printf("pb\n");
}

void	pa(t_shipyard *shipyard)
{
	push(shipyard->ship_b->head->value, \
	shipyard->ship_b->head->index, shipyard->ship_a);
	pop(shipyard->ship_b);
	ft_printf("pa\n");
}
