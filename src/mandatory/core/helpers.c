/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:48:23 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:25:26 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	free_stack(t_ship *ship)
{
	t_container	*current;

	while (ship->head)
	{
		current = ship->head;
		ship->head = ship->head->next;
		free(current);
	}
	free(ship);
}

// void	print_stack(t_ship *ship)
// {
// 	int			i;
// 	t_container	*current;

// 	i = 1;
// 	current = ship->head;
// 	while (current)
// 	{
// 		printf("_____________________________________\n");
// 		printf("Node %d -> Index %d -> Value: %d\n", i, current->index, current->value);
// 		printf(YELLOW"Previous Node Address: %p\n"RESET, current->prev);
// 		printf(RED"Address: %p\n"BLUE, current);
// 		printf(BLUE"Next Node Address: %p\n"RESET, current->next);
// 		printf("_____________________________________\n");
// 		current = current->next;
// 		i++;
// 	}
// }
