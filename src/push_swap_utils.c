/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/14 15:48:06 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap	*parse_arg(char *string);
void	ft_push_swap(t_heap *heap);
void	ft_sort_three(t_heap **heap);

t_heap	*parse_arg(char *string)
{
	t_heap	*stack;
	char	**str_array;
	int		number;
	int 	i;
	
	i = 0;
	str_array = ft_split(string, ' ');
	number = ft_atoi(*str_array);
	stack = ft_heapnew(number);
	str_array++;
	i++;
	while(*str_array)
	{
		number = ft_atoi(*str_array);
		if (ft_is_dup(stack, number) == DUPLICATION_ERROR)
		{
			ft_destroyheap(&stack);
			return (stack);
		}
		else
			ft_heapadd(number, &stack);
		str_array++;
		i++;
	}
	return (stack);
}

void	ft_push_swap(t_heap *heap)
{
	int		size;
	t_heap	*b;

	size = ft_get_size(heap);
	if (size >= 0 && size <= 1)
		return ;
	if (size == 2)
		{
			if(!ft_is_sorted(heap))
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
				// while (ft_get_size(b))
				// 		push_a_to_the_correct_place
				return ;
			}
			push_b(&heap, &b);
			while(ft_get_size(heap) > 3)
			{
				// calculate the cost of each element
				// move the cheapest - push_b_to_the_correct_place
			}
			ft_sort_three(&heap);
			// while (ft_get_size(b))
			// 		push_a_to_the_correct_place
		}
}

void	ft_sort_three(t_heap **heap)
{
	if (!ft_is_sorted(*heap))
		swap_a(heap);
	if (!ft_is_sorted(*heap))
		reverse_rotate_a(heap);
}
