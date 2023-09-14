/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:48:23 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/14 21:27:49 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	print_stack(t_ship *ship)
{
	int			i;
	t_container	*current;

	i = 1;
	current = ship->head;
	while (current)
	{
		printf("_____________________________________\n");
		printf("Node %d -> Index %d -> Value: %d\n",
			i, current->index, current->value);
		printf(YELLOW"Previous Node Address: %p\n"RESET, current->prev);
		printf(RED"Address: %p\n"BLUE, current);
		printf(BLUE"Next Node Address: %p\n"RESET, current->next);
		printf("_____________________________________\n");
		current = current->next;
		i++;
	}
}

long int	long_atoi(const char *str)
{
	size_t	res;
	size_t	i;
	size_t	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}