/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:41:56 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:21:34 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

// [SA] SWAP_A: swaps the first 2 elements at the top of stack A (do nothing if there is only one or no elements).
void	sa(t_ship *ship_a)
{
	int	temp;

	if (!ship_a->head || !ship_a->head->next)
		return ;
	temp = ship_a->head->value;
	ship_a->head->value = ship_a->head->next->value;
	ship_a->head->next->value = temp;
	printf("sa\n");
}

// [SB] SWAP_B: swaps the first 2 elements at the top of stack B (do nothing if there is only one or no elements).
void	sb(t_ship *ship_b)
{
	int	temp;

	if (!ship_b->head || !ship_b->head->next)
		return ;
	temp = ship_b->head->value;
	ship_b->head->value = ship_b->head->next->value;
	ship_b->head->next->value = temp;
	printf("sb\n");
}

void	ss(t_shipyard *shipyard)
{
	sa(shipyard->ship_a);
	sb(shipyard->ship_b);
	printf("ss\n");
}