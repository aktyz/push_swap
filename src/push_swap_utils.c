/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/07 14:42:18 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_arg(char *string)
{
	t_list	*stack;
	int	i;
	int	*ptr;

	i = ft_atoi(string);
	ptr = &i;
	
	stack = ft_lstnew((void *) *ptr);
	
	return (stack);
}
