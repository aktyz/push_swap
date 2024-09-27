/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:02:27 by zslowian          #+#    #+#             */
/*   Updated: 2024/09/27 18:02:27 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Function reverse rotating the stack:
 * - last element become the first
 * - first element become the second
 *
 * Returns a pointer to the stack head.
 */
t_stack	*ft_rev_rotate(t_stack *lifo);
