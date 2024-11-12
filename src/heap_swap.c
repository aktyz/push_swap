/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:21:31 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/11 19:21:31 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap(t_heap **heap);
void	swap_a(t_heap **a);
void	swap_b(t_heap **b);
void	swap_ab(t_heap **a, t_heap **b);

/**
 * Function swap the first two elements fo the heap a
 *
 */
int	swap(t_heap **a)
{
	int	tmp_nb;

	if(!*a || ft_get_size(*a) == 1)
		return (0);
	tmp_nb = (*a)->next->number;
	(*a)->next->number = (*a)->number;
	(*a)->number = tmp_nb;
	return (1);
}

void	swap_a(t_heap **a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	swap_b(t_heap **b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	swap_ab(t_heap **a, t_heap **b)
{
	int	ra;
	int	rb;

	ra = swap(a);
	rb = swap(b);
	if(ra && rb)
		ft_printf("ss\n");
	else if (ra)
		ft_printf("sa\n");
	else if (rb)
		ft_printf("sb\n");
	else
		return ;
}
