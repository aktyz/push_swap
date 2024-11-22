/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:17:52 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/11 19:17:52 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate(t_heap **heap);
void	rotate_a(t_heap **a);
void	rotate_b(t_heap **b);
void	rotate_ab(t_heap **a, t_heap **b);

/** Rotate heap so that:
 * - head element becomes tail
 * - second element becomes head
 */
int	rotate(t_heap **heap)
{
	t_heap	*tail;
	t_heap	*tmp;

	if (ft_get_size(*heap) < 2)
		return (0);
	tmp = (*heap)->next;
	tail = ft_get_tail(*heap);
	tail->next = *heap;
	tail->next->next = 0;
	*heap = tmp;
	return (1);
}

void	rotate_a(t_heap **a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rotate_b(t_heap **b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rotate_ab(t_heap **a, t_heap **b)
{
	int	ra;
	int	rb;

	ra = rotate(a);
	rb = rotate(b);
	if (ra && rb)
		ft_printf("rr\n");
	else if (ra)
		ft_printf("ra\n");
	else if (rb)
		ft_printf("rb\n");
	else
		return ;
}
