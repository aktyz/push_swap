/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/30 16:53:21 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_string_arg(t_heap **heap, char *string);
void	ft_push_swap(t_heap **heap);
void	ft_rot_ab(t_heap *tmp, t_heap **heap, t_heap **b);
void	ft_sort_three(t_heap **heap);
void	ft_push_a_sorted(t_heap **heap, t_heap **b);

/**
 * Function takes string given as program argument and
 * divided it into itegers. Funciton checks agains:
 * - [x] duplication error
 * - [x] not a number error
 * - [ ] MAXINT overrun!!!
 */
void	parse_string_arg(t_heap **heap, char *string)
{
	char		**str_array;
	char		**ptr;
	t_atof		*number;

	str_array = ft_split(string, ' ');
	ptr = str_array;
	if (!*str_array)
	{
		ft_clear_char_array(&ptr);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	number = NULL;
	*heap = NULL;
	while (*str_array)
	{
		number = ft_atof(*str_array);
		ft_check_number(&heap, number);
		str_array++;
		if (number)
			free(number);
		number = NULL;
	}
	ft_clear_char_array(&ptr);
}

/**
 * Function taking the parsed heap and sorting it according
 * to Turk algorithm.
 *
 */
void	ft_push_swap(t_heap **heap)
{
	int		size;
	t_heap	*b;

	size = ft_get_size(*heap);
	b = NULL;
	if (size >= 0 && size <= 1)
		return ;
	if (size == 2)
	{
		if (!ft_is_sorted(*heap))
			swap_a(heap);
	}
	else if (size == 3)
		ft_sort_three(heap);
	else if (!ft_is_sorted(*heap))
	{
		push_b(heap, &b);
		ft_sort_in_b(&heap, &b, size);
		ft_sort_three(heap);
		ft_push_a_sorted(heap, &b);
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

	a_rot = ft_nb_at_head(tmp->number, *heap);
	b_rot = ft_get_b_rot(tmp->number, *b);
	if (a_rot * b_rot > 0)
		ft_rotate_both(&a_rot, &b_rot, &heap, &b);
	ft_rotate(&heap, &a_rot, &rotate_a, &reverse_rotate_a);
	ft_rotate(&b, &b_rot, &rotate_b, &reverse_rotate_b);
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
			a_rot = 0;
		}
		if (a_rot < 0)
		{
			while (a_rot++)
				reverse_rotate_a(heap);
		}
		push_a(heap, b);
	}
}
