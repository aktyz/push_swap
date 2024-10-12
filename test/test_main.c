/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:56:45 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/12 21:59:58 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_heap		*a;
	t_heap		*temp;

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
	temp = a;
	while (temp) // DEBUG
	{
		ft_print_heap_node(temp);
		temp = temp->next;
	}
	ft_print_heap_size(a);
	// sort(stack_a);
	// write_output(result);
	free(a); //My Program
	return (0); //My Program
}