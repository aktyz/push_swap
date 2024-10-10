/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:16:24 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/10 15:03:31 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_heap
{
	int				number;
	int				initial_index;
	int				sorted_index;
	struct s_heap	*next;
} t_heap;

// PROGRAM functions
//void	sort(t_list stack_a);
t_heap	*parse_arg(char *string);

// HEAP functions
t_heap *ft_heapnew(int number, int init_i);
t_heap *ft_heapadd(int number, int init_i, t_heap *heap);
t_heap *ft_gettail(t_heap *heap);
int	ft_is_dup(t_heap *heap, int nb);

// DEBUG/TEST functions
void	ft_print_heap_node(t_heap *node);

#endif
