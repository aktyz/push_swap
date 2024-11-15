/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:56:45 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/15 16:43:37 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_heap	*a;
	t_heap	*temp;
	int		rot;

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
	ft_push_swap(a); //My Program
	rot = ft_nb_at_head(ft_get_min(a), a);
	if (rot > 0)
	{
		while (rot--)
			rotate_a(&a);
	}
	if (rot < 0)
	{
		while (rot++)
			reverse_rotate_a(&a);
	}
	ft_destroyheap(&a); //My Program
	ft_destroyheap(&temp); //My Program
	//ft_printf("\nUNIT TESTS\n");
	//test_ft_get_size();
	//test_push_b();
	//test_ft_is_sorted();
	//test_swap();
	//test_reverse_rotate();
	//test_ft_sort_three();
	//test_ft_get_nb_pos();
	//test_ft_nb_at_head();
	//test_ft_get_b_rot();
	//ft_printf("\nUNIT TESTS COMPLETED\n");
	return (0); //My Program
}
