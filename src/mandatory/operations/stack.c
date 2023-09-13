/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:47:32 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 02:21:17 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// push currently just pushes the value, this has to be changed
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
	t_container *temp;

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
	free (temp);
}
