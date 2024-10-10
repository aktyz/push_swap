/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:46:11 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/10 15:13:36 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_heap	*stack_a;
	
	if (argc != 2)
	{
		write(1, "Error - to little/many arguments", 32);
		return (0); // switch to error message
	}
	else
	stack_a = parse_arg(argv[1]);
	if (!stack_a)
	{
		write(1, "Error - duplicated integers", 27);
		return (0); // switch to error message
	}
	// sort(stack_a);
	// write_output(result);
		return (0);
}
