/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:24:49 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/10 20:28:55 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// HEAP construct & desctruct
t_heap *ft_heapnew(int number);
void	ft_heapadd(int number, t_heap **heap);
void	ft_destroyheap(t_heap **heap);

// HEAPS operations
void	push_b(t_heap **a, t_heap **b);
int		swap(t_heap **heap);
void	swap_a(t_heap **a);
void	swap_b(t_heap **b);
void	swap_ab(t_heap **a, t_heap **b);
int		reverse_rotate(t_heap **heap);
void	reverse_rotate_a(t_heap **a);
void	reverse_rotate_b(t_heap **b);
void	reverse_rotate_ab(t_heap **a, t_heap **b);

// HEAP checks
int		ft_is_dup(t_heap *heap, int nb);
int		ft_is_sorted(t_heap *heap);

t_heap	*ft_heapnew(int number)
{
	t_heap *a;

	a = malloc(sizeof(t_heap));
	a->number = number;
	a->push_b_cost = 0;
	a->distance_from_head = 0;
	a->next = 0;

	return (a);
}

void	ft_heapadd(int number, t_heap **heap)
{
	t_heap *new_node;
	t_heap *tail;

	new_node = malloc(sizeof(t_heap));
	tail = ft_gettail(*heap);
	new_node->number = number;
	new_node->push_b_cost = 0;
	new_node->next = 0;
	new_node->distance_from_head = ft_nb_at_head(number, &heap);

	tail->next = new_node;
}

int	ft_is_dup(t_heap *heap, int nb)
{
	while (heap->next)
	{
		if (heap->number == nb)
			return (DUPLICATION_ERROR);
		heap = heap->next;
	}
	return (OK);
}

void	ft_destroyheap(t_heap **heap)
{
	t_heap *temp;

	while (*heap)
	{
		temp = *heap;
		*heap = (*heap)->next;
		free(temp);
	}
	heap = 0;
}

void	push_b(t_heap **a, t_heap **b)
{
	t_heap *temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = temp->next;
	if (ft_get_size(*b) == 0)
		*b = ft_heapnew(temp->number);
	else
	{
		temp->next = *b;
		*b = temp;
	}
	ft_printf("pb\n");
}

void	push_a(t_heap **a, t_heap **b)
{
	t_heap *temp;

	if (!(*b))
		return ;
	temp = *b;
	*b = temp->next;
	if (ft_get_size(*a) == 0)
		*a = ft_heapnew(temp->number);
	else
	{
		temp->next = *a;
		*a = temp;
	}
	ft_printf("pa\n");
}

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

/** Rotate heap so that:
 * - head element becomes tail
 * - second element becomes head
 */
int rotate(t_heap **heap)
{
	t_heap	*tail;
	t_heap	*tmp;

	if (ft_get_size(*heap) < 2)
		return (0);
	tmp = *heap->next;
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
	if(ra && rb)
		ft_printf("rr\n");
	else if (ra)
		ft_printf("ra\n");
	else if (rb)
		ft_printf("rb\n");
	else
		return ;
}

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
	tail = ft_gettail(*heap);
	while (tmp->next != tail)
		tmp = tmp->next;
	tmp->next = 0;
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
	if(ra && rb)
		ft_printf("rrr\n");
	else if (ra)
		ft_printf("rra\n");
	else if (rb)
		ft_printf("rrb\n");
	else
		return ;
}

int		ft_is_sorted(t_heap *heap)
{
	int		tmp_nb;

	if (ft_get_size(heap) < 2)
		return (1);
	tmp_nb = heap->number;
	heap = heap->next;
	while (heap)
	{
		if (tmp_nb < heap->number)
		{
			tmp_nb = heap->number;
			heap = heap->next;
		}
		else
			return (0);
	}
	return (1);
}
