/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_cost_calculation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:33:16 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/14 22:28:43 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap	*ft_cost_calculation(t_heap *a, t_heap *b);
int		ft_node_cost_calculation(int nb, t_heap *a, t_heap *b);
int		ft_get_heap_b_rotation(int nb, t_heap *b);
int		ft_nb_at_head(int nb, t_heap *heap);

/**
 * Function calculates the cost (necessary number of operations) for each node
 * of heap a to be moved to the correct place in heap_b as per Turk algorithm.
 * 
 * The cost of the node is stored in the node structure. Function returns
 * a pointer to the node with lowest cost.
 * 
 * Both stacks are not modified in any way in this function.
 * 
*/
t_heap	*ft_cost_calculation(t_heap *a, t_heap *b)
{
	t_heap	*head;
	int		lowest;

	head = a;
	while (a)
	{
		a->push_b_cost = ft_node_cost_calculation(a->number, head, b);
		a = a->next;
	}
	a = head;
	lowest = a->push_b_cost;
	while (a)
	{
		if (a->push_b_cost < lowest)
		{
			lowest = a->push_b_cost;
			head = a;
		}
		a = a->next;
	}
	return (head);
}

int	ft_node_cost_calculation(int nb, t_heap *a, t_heap *b)
{
	int	a_rotation;
	int	b_rotation;
	
	a_rotation = ft_nb_at_head(nb, a);
	b_rotation = ft_get_heap_b_rotation(nb, b);
	return (ft_max(a_rotation, b_rotation) + 1); // TODO: correct
}

/**
 * This one is tricky - we need to rotate B so that we have a node->number > nb
 * at the head, and ... yeah... exactly, kind of difficult to explain
 * 
 * Developed when running different examples of this rotation.
*/
int	ft_get_heap_b_rotation(int nb, t_heap *b)
{
	int		new_head_nb;
	int		prev;
	t_heap	*head;
	
	prev = b->number;
	head = b;
	if (head->number > nb)
	{
		while (b && b->number > nb)
		{
			if (b->number > prev)
				break;
			prev = b->number;
			b = b->next;
		}
	}
	else if (head->number < nb)
	{
		while (b && b->number < nb)
		{
			if (b->number > prev)
				break;
			prev = b->number;
			b = b->next;
		}
	}
	if (!b)
		new_head_nb = head->number;
	new_head_nb = b->number;
	return (ft_nb_at_head(new_head_nb, b));
}

/**
 * Function returning number representing the rotation of the heap,
 * that will result nb being at the head of it.
 * 
 * If the return nb is positive we are rotatating (shifting up)
 * If the return nb is negative we should reverse rotate (shift down)
 * 
 * TODO: correct
*/
int	ft_nb_at_head(int nb, t_heap *heap)
{
	int nb_pos;
	int	a_size;
	
	nb_pos = ft_get_nb_pos(nb, heap);
	a_size = ft_get_size(heap);
	if (nb_pos < a_size/2)
		return (nb_pos);
	else
		return (a_size - nb_pos);
}
