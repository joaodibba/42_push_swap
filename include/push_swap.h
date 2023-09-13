/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:33:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 16:49:45 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>

// PRINTF_COLORS
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define BLUE "\e[0;34m"
# define PURPLE "\e[0;35m"
# define YELLOW "\e[0;33m"
# define RESET "\e[0;37m"
# define CLEAR "\033c"

typedef struct s_container // CONTAINER -> NODE     
{
	int					value;
	int					index;
	struct s_container	*prev;
	struct s_container	*next;
}						t_container;

typedef struct s_ship // SHIP -> STACK / LINKED LIST   
{
	struct s_container	*head;
	struct s_container	*tail;
}						t_ship;

typedef struct s_shipyard // SHIPYARD -> GENERAL STRUCTURE
{
	struct s_ship	*ship_a;
	struct s_ship	*ship_b;
}					t_shipyard;

void		sort(t_shipyard *shipyard);
bool		is_sorted(t_ship *ship);
void		sort_three(t_shipyard *shipyard);
void		sort_five(t_shipyard *shipyard);
void		radix(t_shipyard *shipyard);
int			find_max_bits(t_ship *ship);
void		sort_merda(t_shipyard *shipyard); //lixo

void		pop(t_ship *ship);
void		push(int value,	int index, t_ship *ship);

void		sa(t_ship *ship_a);
void		sb(t_ship *ship_b);
void		ss(t_shipyard *shipyard);

void		ra(t_ship *ship_a);
void		rb(t_ship *ship_b);
void		rr(t_shipyard *shipyard);

void		rra(t_ship *ship_a);
void		rrb(t_ship *ship_b);
void		rrr(t_shipyard *shipyard);

void		pb(t_shipyard *shipyard);
void		pa(t_shipyard *shipyard);

int			list_size(t_container *head);
void		printLinkedList(t_ship *ship);

void		print_stack(t_ship *ship); //

#endif