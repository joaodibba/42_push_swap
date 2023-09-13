/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:04:48 by jalves-c          #+#    #+#             */
/*   Updated: 2023/09/13 16:47:58 by jalves-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <string.h>

bool arguments_are_duplicated(int ac, char **av)
{
    int i;
	int j;
    bool duplicate_found;
	
	i = 1;
	j = 0;
	duplicate_found = false;
    while (i < ac - 1 && !duplicate_found)
	{
        j = i + 1;
        while (j < ac && !duplicate_found)
		{
            if (ft_strcmp(av[i], av[j]) == 0)
			{
                duplicate_found = true;
                ft_printf("AV[%d] ", i);
				ft_printf("AND AV[%d] ARE THE SAME\n", j);
            }
            j++;
        }
        i++;
    }
    return (duplicate_found);
}

bool	arguments_are_within_integer_range(char *av)
{
	if ((av[0] == '-' && (ft_strlen(av) > 11 || \
		(ft_strlen(av) == 11 && ft_strcmp(av, "-2147483648") > 0))) || \
		(av[0] != '-' && (ft_strlen(av) > 10 || \
		(ft_strlen(av) == 10 && ft_strcmp(av, "2147483647") > 0))))
		return (false);
	return (true);
}

bool	arguments_are_numbers(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (av[i] == '\0')
		return (false);
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	arguments_are_valid(int ac, char **av)
{
	if (arguments_are_duplicated(ac, av) == true)
	{
		ft_printf("Error [DUPLICATES].\n");
		return (false);
	}
	while (ac-- > 1)
	{
		if (arguments_are_numbers(av[ac]) != true)
		{
			ft_printf("Error [NOT A NUMBER].\n");
			return (false);
		}
		if (arguments_are_within_integer_range(av[ac]) != true)
		{
			ft_printf("Error [NOT A INTEGER].\n");
			return (false);
		}
	}
	return (true);
}

void	print_stack(t_ship *ship)
{
	t_container *current;

	current = ship->head;
	ft_printf("index: ");
	while(current)
	{
		ft_printf("%d ", current->index);
		current = current->next;
	}
	current = ship->head;
	ft_printf("\nvalor: ");
	while(current)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

t_ship *add_back(int value, t_ship *ship)
{
	t_container *new_node = (t_container *)malloc(sizeof(t_container));
	if (!new_node) 
	{
		// Handle memory allocation failure here.
		return (NULL);
	}
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

void create_stack(int ac, char **av, t_shipyard *shipyard)
{
    int i; 

    i = 1;
    while (i < ac)
    {
        shipyard->ship_a = add_back(ft_atoi(av[i]), shipyard->ship_a);
        i++;
    }
}

void	printLinkedList(t_ship *ship)
{
	int i = 1;

	t_container *current = ship->head;
	
	while (current != NULL) 
	{
		printf("_____________________________________\n");
		printf("Node %d -> Index %d -> Value: %d\n", i, current->index, current->value);
		printf(YELLOW"Previous Node Address: %p\n"RESET,current->prev);
		printf(RED"Address: %p\n"BLUE, current);
		printf(BLUE"Next Node Address: %p\n"RESET, current->next);
		printf("_____________________________________\n");
		current = current->next;
		i++;
	}
}

int main(int ac, char **av)
{
    t_shipyard shipyard;

    if (!arguments_are_valid(ac, av))
    {
        ft_printf("Error\n");
        return (1);
    }

    shipyard.ship_a = (t_ship *)malloc(sizeof(t_ship));
    if (!shipyard.ship_a) 
	{
        ft_printf("Error [MEMORY ALLOCATION FAILED].\n");
        return (1);
    }
	
    shipyard.ship_a->head = NULL;
    shipyard.ship_a->tail = NULL;
    shipyard.ship_b->head = NULL;
    shipyard.ship_b->tail = NULL;	
	
    create_stack(ac, av, &shipyard);
    if (!shipyard.ship_a->head)
    {
		ft_printf("Error [EMPTY LIST].\n");
		return (1);
	}
	sort(&shipyard);
	// printLinkedList(shipyard.ship_a);
	// printf("B\n");
	// printLinkedList(shipyard.ship_b);
    return (0);
}
