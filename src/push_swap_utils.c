/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/06 20:53:45 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_arg(char *string)
{
	t_list	*stack;
	char 	**numbers;
	int		count;
	int		i;

	count = 1;
	i = 0;
	numbers = ft_split(string, ' ');
	while (*numbers[i])
	{
		printf("Number %d:\t \"%c\"", count, *numbers[i]);
		i++;
		count++;
	}
	stack = ft_lstnew(&numbers);
	return (stack);
}
