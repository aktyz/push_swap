/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:16:24 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/03 13:51:04 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_stack {
	int		number;
	t_stack	*next;
} t_stack;

// PROGRAM functions
int		sort_stack(t_stack a);
void	sort_input(char *input);
t_stack	read_input(char *input);

// STACK funtions
void	ft_pop(t_stack *stack);
t_stack	*ft_swap(t_stack *stack);
t_stack	*ft_peek(t_stack *stack);
t_stack	*ft_rotate(t_stack *stack);
t_stack	*ft_rev_rotate(t_stack *stack);
t_stack	*ft_push(t_stack *stack, int number);

#endif
