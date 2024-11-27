/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:20:21 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/11 19:20:21 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		reverse_rotate(t_heap **heap);
void	reverse_rotate_a(t_heap **a);
void	reverse_rotate_b(t_heap **b);
void	reverse_rotate_ab(t_heap **a, t_heap **b);

/**
 * Rotate heap so that:
 * - the last element becomes the head,
 * - the head element becomes second element
 */
int	reverse_rotate(t_heap **heap)
{
	t_heap	*tail;
	t_heap	*tmp;

	if (ft_get_size(*heap) < 2)
		return (0);
	tmp = *heap;
	tail = ft_get_tail(*heap);
	while (tmp->next != tail)
		tmp = tmp->next;
	tmp->next = NULL;
	tail->next = *heap;
	*heap = tail;
	return (1);
}

void	reverse_rotate_a(t_heap **a)
{
	if (reverse_rotate(a))
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_heap **b)
{
	if (reverse_rotate(b))
		ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_heap **a, t_heap **b)
{
	int	ra;
	int	rb;

	ra = reverse_rotate(a);
	rb = reverse_rotate(b);
	if (ra && rb)
		ft_printf("rrr\n");
	else if (ra)
		ft_printf("rra\n");
	else if (rb)
		ft_printf("rrb\n");
	else
		return ;
}
