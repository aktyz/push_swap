/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:56:45 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/22 16:38:03 by zslowian         ###   ########.fr       */
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
		return (0);
		else
		{
			ft_printf("\nBefore parsing\n");
			a = parse_arg(argv[1]);
			ft_printf("\nAfter parsing\n");
		}
		if (!a)
		{
			write(1, "Error - duplicated integers\n", 28);
			return (0);
		}
		temp = a;
		while (temp)
		{
			ft_print_heap_node(temp);
			temp = temp->next;
		}
		ft_push_swap(a);
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
		ft_destroyheap(&a);
		ft_destroyheap(&temp);
		ft_printf("\nUNIT TESTS\n");
		test_ft_atof();
		ft_printf("\nUNIT TESTS COMPLETED\n");
		return (0);
	}
}
