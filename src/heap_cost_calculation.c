/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_cost_calculation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:33:16 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/25 18:40:55 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap	*ft_get_lowest_cost_node(t_heap *a, t_heap *b);
int		ft_node_cost_calculation(int nb, t_heap *a, t_heap *b);
int		ft_get_b_rot(int nb, t_heap *b);
int		ft_get_a_rot(int nb, t_heap *a);
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
t_heap	*ft_get_lowest_cost_node(t_heap *a, t_heap *b)
{
	t_heap	*head;
	int		lowest;

	head = a;
	while (a)
	{
		a->push_b_cost = ft_node_cost_calculation(a->number, head, b);
		a->distance_from_head = ft_nb_at_head(a->number, a);
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

/**
 * This function returns the cost of pushing node holding nb value
 * from heap a to the head of heap b.
 *
 * It returns a positive value of the cost, no matter which direction
 * we need to turn a and b.
 *
 */
int	ft_node_cost_calculation(int nb, t_heap *a, t_heap *b)
{
	int	a_rotation;
	int	b_rotation;

	a_rotation = ft_nb_at_head(nb, a);
	b_rotation = ft_get_b_rot(nb, b);
	if (a_rotation * b_rotation > 0)
	{
		a_rotation = ft_absolute(a_rotation);
		b_rotation = ft_absolute(b_rotation);
		return (ft_max(a_rotation, b_rotation) + 1);
	}
	else
	{
		a_rotation = ft_absolute(a_rotation);
		b_rotation = ft_absolute(b_rotation);
		return (a_rotation + b_rotation + 1);
	}
}

/**
 * This function finds the b heap node that should land at the head of
 * b heap in order to be able to push_b nb in the right place.
 *
 * In general case the new number should have a bigger number above
 * (in the tail) and smaller number below (at the head).
 *
 * Two corner cases are when we are entering new biggest number or
 * new smallest number - in this case we want the biggest number of the
 * heap at the head of the heap for insertion.
 *
 * It then returns the number of rotations to get this node
 * to the head of heap b.
 *
 * Developed when running different examples of this rotation.
 *
*/
int	ft_get_b_rot(int nb, t_heap *b)
{
	t_heap	*is_new_head;
	int		prev_nb;

	if (!b)
		return (0);
	if (ft_get_max(b) < nb || ft_get_min(b) > nb)
		return (ft_nb_at_head(ft_get_max(b), b));
	is_new_head = b;
	prev_nb = ft_get_tail(b)->number;
	while (is_new_head)
	{
		if (prev_nb > nb && is_new_head->number < nb)
			break ;
		prev_nb = is_new_head->number;
		is_new_head = is_new_head->next;
	}
	return (ft_nb_at_head(is_new_head->number, b));
}

/**
 * This function finds the a heap node that should land at the head of
 * a heap in order to be able to push_a nb in the right place.
 *
 * In general case the new number should have a smaller number above
 * (in the tail) and bigger number below (at the head).
 *
 * Two corner cases are when we are entering new biggest number or
 * new smallest number - in this case we want the smallest number of the
 * heap at the head of the heap for insertion.
 *
 * It then returns the number of rotations to get this node
 * to the head of heap a.
 *
 * Developed by modifying ft_get_b_rot().
 *
*/
int	ft_get_a_rot(int nb, t_heap *a)
{
	t_heap	*is_new_head;
	int		prev_nb;

	if (!a)
		return (0);
	if (ft_get_max(a) < nb || ft_get_min(a) > nb)
		return (ft_nb_at_head(ft_get_min(a), a));
	is_new_head = a;
	prev_nb = ft_get_tail(a)->number;
	while (is_new_head)
	{
		if (prev_nb < nb && is_new_head->number > nb)
			break ;
		prev_nb = is_new_head->number;
		is_new_head = is_new_head->next;
	}
	return (ft_nb_at_head(is_new_head->number, a));
}

/**
 * Function returning number representing the rotation of the heap,
 * that will result nb being at the head of it.
 *
 * If the return nb is positive we are rotatating (shifting up)
 * If the return nb is negative we should reverse rotate (shift down)
 *
*/
int	ft_nb_at_head(int nb, t_heap *heap)
{
	int	nb_pos;
	int	a_size;
	int	i;

	a_size = ft_get_size(heap);
	if (a_size < 2)
		return (0);
	nb_pos = ft_get_nb_pos(nb, heap) + 1;
	if (nb_pos < (a_size / 2 + 1))
		return (nb_pos - 1);
	else
	{
		i = (a_size - nb_pos + 1) * -1;
		if (a_size == 2 && i == -1)
			return (1);
		else if (a_size == 3 && i == -2)
			return (1);
		else
			return (i);
	}
}
