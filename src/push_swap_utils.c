/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/10 15:35:28 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
