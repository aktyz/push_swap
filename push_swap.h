/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:16:24 by zslowian          #+#    #+#             */
/*   Updated: 2024/09/27 18:04:58 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack {
	int		number;
	t_stack	*next;
} t_stack;

void	ft_pop(t_stack *lifo);
t_stack	*ft_swap(t_stack *lifo);
t_stack	*ft_peek(t_stack *lifo);
t_stack	*ft_rotate(t_stack *lifo);
t_stack	*ft_rev_rotate(t_stack *lifo);
t_stack	*ft_push(t_stack *lifo, int number);

#endif
