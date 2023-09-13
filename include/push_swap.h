/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:33:09 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 21:53:02 by jalves-c         ###   ########.fr       */
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

// STRUCTURES [SHIPYARD->SHIP->CONTAINER]
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

// VALIDATIONS
bool		arguments_are_valid(int ac, char **av);
bool		arguments_are_duplicated(int ac, char **av);
bool		arguments_are_within_integer_range(char *av);
bool		arguments_are_numbers(char *av);

// STACK CREATION AND MANAGEMENT
void		create_stack(int ac, char **av, t_shipyard *shipyard);
void		pop(t_ship *ship);
void		push(int value,	int index, t_ship *ship);
int			stack_size(t_container *head);
void		free_stack(t_ship *ship);
void		print_stack(t_ship *ship);

// SORTING
void		sort(t_shipyard *shipyard);
void		sort_three(t_shipyard *shipyard);
void		sort_five(t_shipyard *shipyard);
void		radix(t_shipyard *shipyard);
int			find_max_bits(t_ship *ship);
bool		is_sorted(t_ship *ship);

// SORTING -> MOVES
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

#endif