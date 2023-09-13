/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:47:32 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:25:32 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

t_ship	*add_back(int value, t_ship *ship)
{
	t_container		*new_node;

	new_node = (t_container *)malloc(sizeof(t_container));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (!ship->tail)
	{
		ship->head = new_node;
		ship->tail = new_node;
	}
	else
	{
		ship->tail->next = new_node;
		new_node->prev = ship->tail;
		ship->tail = new_node;
	}
	return (ship);
}

void	create_stack(int ac, char **av, t_shipyard *shipyard)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		shipyard->ship_a = add_back(ft_atoi(av[i]), shipyard->ship_a);
		i++;
	}
}
