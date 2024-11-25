/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/25 17:45:04 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap	*parse_string_arg(char *string);
void	ft_push_swap(t_heap *heap);
void	ft_rot_ab(t_heap *tmp, t_heap **heap, t_heap **b);
void	ft_sort_three(t_heap **heap);
void	ft_push_a_sorted(t_heap **heap, t_heap **b);

/**
 * Function takes string given as program argument and
 * divided it into itegers. Funciton checks agains:
 * - [x] duplication error
 * - [ ] not a number error
 * - [ ] MAXINT overrun
 */
t_heap	*parse_string_arg(char *string)
{
	t_heap	*stack;
	char	**str_array;
	int		number;
	int		i;

	i = 0;
	str_array = ft_split(string, ' ');
	number = ft_atoi(*str_array);
	stack = ft_heapnew(number);
	str_array++;
	i++;
	while (*str_array)
	{
		number = ft_atoi(*str_array);
		if (ft_is_dup(stack, number) == DUPLICATION_ERROR)
		{
			ft_destroyheap(&stack);
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else
			ft_heapadd(number, &stack);
		str_array++;
		i++;
	}
	return (stack);
}

/**
 * Function taking the parsed heap and sorting it according
 * to Turk algorithm.
 * 
 */
void	ft_push_swap(t_heap *heap)
{
	int		size;
	t_heap	*tmp;
	t_heap	*b;

	size = ft_get_size(heap);
	if (size >= 0 && size <= 1)
		return ;
	if (size == 2)
	{
		if (!ft_is_sorted(heap))
			swap_a(&heap);
	}
	else if (size == 3)
		ft_sort_three(&heap);
	else
	{
		push_b(&heap, &b);
		if (ft_get_size(heap) == 3)
		{
			ft_sort_three(&heap);
			while (ft_get_size(b))
				ft_push_a_sorted(&heap, &b);
			return ;
		}
		push_b(&heap, &b);
		while (ft_get_size(heap) > 3)
		{
			tmp = ft_get_lowest_cost_node(heap, b);
			ft_rot_ab(tmp, &heap, &b);
			push_b(&heap, &b);
		}
		ft_sort_three(&heap);
		while (ft_get_size(b))
			ft_push_a_sorted(&heap, &b);
	}
}

/**
 * This function modifies both heap and heap b:
 * - tmp node is moved to the head of heap
 * - b is rotated so that we end up with node->number > tmp->nb at the head
 *
 */
void	ft_rot_ab(t_heap *tmp, t_heap **heap, t_heap **b)
{
	int	a_rot;
	int	b_rot;
	int	min;

	a_rot = tmp->distance_from_head;
	b_rot = ft_get_b_rot(tmp->number, *b);
	if (a_rot * b_rot > 0)
	{
		min = ft_min(ft_absolute(a_rot), ft_absolute(b_rot));
		while (min--)
		{
			if (a_rot > 0)
			{
				rotate_ab(heap, b);
				a_rot--;
				b_rot--;
			}
			else if (a_rot < 0)
			{
				reverse_rotate_ab(heap, b);
				a_rot++;
				b_rot++;
			}
		}
		if (a_rot != 0)
		{
			if (a_rot > 0)
			{
				while (a_rot--)
					rotate_a(heap);
			}
			else
			{
				while (a_rot++)
					reverse_rotate_a(heap);
			}
		}
		if (b_rot != 0)
		{
			if (b_rot > 0)
			{
				while (b_rot--)
					rotate_b(b);
			}
			else
			{
				while (b_rot++)
					reverse_rotate_b(b);
			}
		}
	}
	else
	{
		if (a_rot != 0)
		{
			if (a_rot > 0)
			{
				while (a_rot--)
					rotate_a(heap);
			}
			else
			{
				while (a_rot++)
					reverse_rotate_a(heap);
			}
		}
		if (b_rot != 0)
		{
			if (b_rot > 0)
			{
				while (b_rot--)
					rotate_b(b);
			}
			else
			{
				while (b_rot++)
					reverse_rotate_b(b);
			}
		}
	}
}

/**
 * Function sorting the heap if it has only three arguments
 *
 */
void	ft_sort_three(t_heap **heap)
{
	if (!ft_is_sorted(*heap))
		swap_a(heap);
	if (!ft_is_sorted(*heap))
		reverse_rotate_a(heap);
}

/**
 * This function rotates a if necessary and push b head
 * to a in the right order
 *
 */
void	ft_push_a_sorted(t_heap **heap, t_heap **b)
{
	int	a_rot;

	while (*b)
	{
		a_rot = ft_get_a_rot((*b)->number, *heap);
		if (a_rot > 0)
		{
			while (a_rot--)
				rotate_a(heap);
		}
		if (a_rot < 0)
		{
			while (a_rot++)
				reverse_rotate_a(heap);
		}
		push_a(heap, b);
	}
}
