/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:19:57 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/06 20:32:20 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	parse_arg(char *string)
{
	t_list	stack;
	char 	**numbers;
	int		count;

	count = 1;
	numbers = ft_split(string, " ");
	while (**numbers)
	{
		printf("Number %d:\t \"%s\"", count, *numbers);
		**numbers++;
		count++;
	}
	return (stack);
}
