/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:46:11 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/25 15:40:04 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_finish_sorting(t_heap **heap);

int	main(int argc, char *argv[])
{
	t_heap	*stack_a;
	int		rot;

	if (argc != 2)
	{
		write(1, "Error - to little/many arguments\n", 33);
		return (0);
	}
	else
		stack_a = parse_arg(argv[1]);
	if (!stack_a)
	{
		write(1, "Error - duplicated integers\n", 28);
		return (0);
	}
	ft_push_swap(stack_a);
	ft_finish_sorting(&stack_a);
	ft_destroyheap(&stack_a);
	return (0);
}

/**
 * Function makes sure that the heap min number is at 
 * it's head.
 * 
 */
static void	ft_finish_sorting(t_heap **heap)
{
	int	rot;

	rot = ft_nb_at_head(ft_get_min(heap), heap);
	if (rot > 0)
	{
		while (rot--)
			rotate_a(&heap);
	}
	if (rot < 0)
	{
		while (rot++)
			reverse_rotate_a(&heap);
	}
}
