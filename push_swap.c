/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:46:11 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/03 13:49:11 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	if (!argc || (argc < 2 || argc > 2))
		return (0);
	else
		sort_input(argv[1]);
	return (0);
}

void	sort_input(char *input)
{
	t_stack	a;
	int		operations_nbr;
	
	a = read_input(input);
	operations_nbr = sort_stack(a);
}
