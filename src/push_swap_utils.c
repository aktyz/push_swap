/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/13 16:11:46 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap	*parse_arg(char *string);
void	ft_push_swap(t_heap *heap);

t_heap	*parse_arg(char *string)
{
	t_heap	*stack;
	char	**str_array;
	int		number;
	int 	i;
	
	i = 0;
	str_array = ft_split(string, ' ');
	number = ft_atoi(*str_array);
	stack = ft_heapnew(number, i);
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
			stack = ft_heapadd(number, i, stack);
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
			// check if sorted - ie. min at the top
			// if not swap a
		}
	if (size == 3)
		{
			// check if sorted - ie. min at the top
			// sort three elements heap
		}
	else 
		{
			push_b(&heap, &b);
			// check size A if not 3
			push_b(&heap, &b);
			
			while(size > 3)
			{
				// calculate the cost of each element
				// move the cheapest - push_b_to_the_correct_place
				size = ft_get_size(heap);
			}
			// sort three elements heap
			// push_a_to_the_correct_place
		}
}