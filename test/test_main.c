/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:56:45 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/13 14:37:22 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	/**t_heap		*a;
	t_heap		*temp;

	if (argc != 2)
	{
		write(1, "Error - to little/many arguments\n", 33);
		return (0); // switch to error message
	}
	else
	{
		ft_printf("\nBefore parsing\n");
		a = parse_arg(argv[1]); //My Program
		ft_printf("\nAfter parsing\n");
	}
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
	// ft_push_swap(a); //My Program
	free(a); //My Program
	free(temp); //My Program */
	ft_printf("\nUNIT TESTS\n");
	//test_ft_get_size();
	//test_push_b();
	//test_ft_is_sorted();
	//test_swap();
	//test_reverse_rotate();
	//test_ft_sort_three();
	//test_ft_get_nb_pos();
	test_ft_nb_at_head();
	ft_printf("\nUNIT TESTS COMPLETED\n");
	return (0); //My Program
}
