/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:56:45 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/12 19:25:55 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_heap		*a;

	if (argc != 2)
	{
		write(1, "Error - to little/many arguments\n", 33);
		return (0); // switch to error message
	}
	else
	a = parse_arg(argv[1]); //My Program
	if (!a) //My Program
	{
		write(1, "Error - duplicated integers\n", 28);
		return (0); // switch to error message
	}
	while (a) // DEBUG
	{
		ft_print_heap_node(a);
		a = a->next;
	}
	// sort(stack_a);
	// write_output(result);
	free(a); //My Program
	return (0); //My Program
}