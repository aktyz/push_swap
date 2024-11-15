/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:46:11 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/15 16:38:55 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void	ft_get_min_at_head(**heap);

int main(int argc, char *argv[])
{
	t_heap	*stack_a;
	int		rot;

	if (argc != 2)
	{
		write(1, "Error - to little/many arguments\n", 33);
		return (0); // switch to error message
	}
	else
	stack_a = parse_arg(argv[1]);
	if (!stack_a)
	{
		write(1, "Error - duplicated integers\n", 28);
		return (0); // switch to error message
	}
	ft_push_swap(stack_a);
	rot = ft_nb_at_head(ft_get_min(stack_a), stack_a);
	if (rot > 0)
	{
		while (rot--)
			rotate_a(&stack_a);
	}
	if (rot < 0)
	{
		while (rot++)
			reverse_rotate_a(&stack_a);
	}
	ft_destroyheap(&stack_a);
	return (0);
}

/*static void	ft_get_min_at_head(**heap)
{
	int	rot;

	rot = ft_nb_at_head(ft_get_min(*heap), &heap);
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
}*/
