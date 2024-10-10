/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:56:45 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/10 15:36:41 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	char		*str;
	t_heap		*a;

	str = ft_calloc(sizeof(char), 20);
	ft_strlcpy(str, "33 965 77 0 77 7", 17);	
	ft_printf("%s\n", str);
	a = parse_arg(str);
	if (!a)
	{
		write(1, "Error - duplicated integers\n", 28);
		return (0); // switch to error message
	}
	while (a) // DEBUG
	{
		ft_print_heap_node(a);
		a = a->next;
	}
	free(a);
	return (0);
}