/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:46:11 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/27 14:37:25 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_args(t_heap **heap, char **argv);
static void	ft_finish_sorting(t_heap **heap);

int	main(int argc, char *argv[])
{
	t_heap	*stack_a;

	stack_a = NULL;
	if (argc == 2)
		parse_string_arg(&stack_a, argv[1]);
	else if (argc > 2)
		parse_args(&stack_a, argv);
	else
		exit(EXIT_FAILURE);
	ft_push_swap(&stack_a);
	ft_finish_sorting(&stack_a);
	ft_destroyheap(&stack_a);
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

	i = 1;
	heap = NULL;
	while (argv[i])
	{
		number = ft_atof(argv[i]);
		if (ft_is_dup(*heap, number->number) == DUPLICATION_ERROR)
		{
			ft_destroyheap(heap);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else
			ft_heapadd(number->number, heap);
		i++;
		free(number);
		number = NULL;
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
