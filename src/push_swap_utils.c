/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/07 15:32:43 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heap	*parse_arg(char *string)
{
	t_heap	*stack;
	int	i;
	int init_i;
	
	i = ft_atoi(string);
	init_i = 0;
	stack = ft_heapnew(i, init_i);
	return (stack);
}
