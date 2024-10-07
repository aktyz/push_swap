/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_print_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:02:26 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/07 16:05:54 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_heap_node(t_heap *node)
{
	ft_printf("New node:\n");
	ft_printf("\tValue stored in node:\t%d\n", node->number);
	ft_printf("\tInitial index of the node:\t%d\n", node->initial_index);
	ft_printf("\tSorted index of the node:\t%d\n", node->sorted_index);
}