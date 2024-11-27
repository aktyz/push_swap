/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atof_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:10:00 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/27 14:03:05 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_atof(void)
{
	t_atof	*result;

	ft_printf("\n--------Testing ft_atof--------\n");
	result = ft_atof("-2147483648");
	ft_printf("\n\nresult.number = %f\t\t result.error = %s\n\n",
		result->number, result->error);
	if (result->number == -2147483648 && !result->error)
		ft_printf("\nTest 0 passed\n");
	else
		ft_printf("\nTest 0: Expected -2147483648, got: %f\n", result->number);
	free(result);
	result = NULL;
}
