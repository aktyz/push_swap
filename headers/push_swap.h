/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:16:24 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/29 16:36:59 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_heap
{
	int				number;
	int				push_b_cost;
	struct s_heap	*next;
} t_heap;

typedef enum e_push_swap_error
{
	DUPLICATION_ERROR = -33,
}	t_push_swap_error;

// PROGRAM functions
t_heap	*parse_arg(char *string);
void	ft_push_swap(t_heap *heap);
void	ft_sort_three(t_heap **heap);
t_heap	*ft_cost_calculation(t_heap *a, t_heap *b);
int		ft_node_cost_calculation(int nb, t_heap *a, t_heap *b);
int		ft_get_heap_b_rotation(int nb, t_heap *b);
int		ft_nb_at_head(int nb, t_heap *heap);

// HEAP construct & desctruct
t_heap	*ft_heapnew(int number);
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

// HEAP getters
t_heap	*ft_gettail(t_heap *heap);
int		ft_get_size(t_heap *heap);
int		ft_get_min(t_heap *heap);
int		ft_get_nb_pos(int nb, t_heap *heap);

// HEAP checks
int		ft_is_dup(t_heap *heap, int nb);
int		ft_is_sorted(t_heap *heap);

// DEBUG/TEST functions
void	ft_print_heap_node(t_heap *node);
void	ft_print_heap(t_heap *heap);
void	ft_print_heap_size(t_heap *heap);
void	ft_print_ab(t_heap *a, t_heap *b);
void	test_ft_is_sorted(void);
void	test_ft_get_size(void);
void	test_push_b(void);
void	test_swap(void);
void	test_reverse_rotate(void);
void	test_ft_sort_three(void);

#endif
