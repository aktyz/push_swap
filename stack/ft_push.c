/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:54:44 by zslowian          #+#    #+#             */
/*   Updated: 2024/09/27 17:54:44 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function push a number to the top of the stack.
 * If there is no stack, it creates it.
 *
 * Returns a pointer to the stack head.
 *
 */
t_stack	*ft_push(t_stack *lifo, int number);
