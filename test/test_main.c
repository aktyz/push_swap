/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:56:45 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/25 18:54:39 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_args(t_heap **heap, char **argv);
static void	ft_finish_sorting(t_heap **heap);

int	main(int argc, char *argv[])
{
	t_heap	*stack_a;

	if (argc == 2)
		stack_a = parse_string_arg(argv[1]);
	else if (argc > 2)
		parse_args(&stack_a, argv);
	else
		exit(EXIT_FAILURE);
	ft_push_swap(&stack_a);
	ft_finish_sorting(&stack_a);
	ft_destroyheap(&stack_a);
	ft_printf("\nUNIT TESTS\n");
	test_ft_nb_at_head();
	test_ft_node_cost_calculation();
	ft_printf("\nUNIT TESTS COMPLETED\n");
	return (0);
}

/**
 * Function parsing integers from a list of program arguments.
 *
 */
static void	parse_args(t_heap **heap, char **argv)
{
	int		i;
	t_atof	*number;

	number = ft_atof(argv[1]);
	*heap = ft_heapnew(number->number);
	i = 2;
	free(number);
	while (argv[i])
	{
		number = ft_atof(argv[i]);
		if (ft_is_dup(*heap, number->number) == DUPLICATION_ERROR)
		{
			ft_destroyheap(heap);
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else
			ft_heapadd(number->number, heap);
		i++;
		free(number);
	}
}

/**
 * Function makes sure that the heap min number is at
 * it's head.
 *
 */
static void	ft_finish_sorting(t_heap **heap)
{
	int	rot;

	rot = ft_nb_at_head(ft_get_min(*heap), *heap);
	if (rot > 0)
	{
		while (rot--)
			rotate_a(heap);
	}
	if (rot < 0)
	{
		while (rot++)
			reverse_rotate_a(heap);
	}
}
