/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atof.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:48:22 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/27 16:51:10 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_overflow(t_atof **result, char next);

/**
 * Function converting string to float for push_swap project.
 *
 * If the resulting number is bigger than MAX_INT or smaller
 * than MIN_INT the program will return it with atof_error
 * set to OVERFLOW
 *
 */
t_atof	*ft_atof(const char *str)
{
	int		i;
	int		is_negative;
	t_atof	*result;

	i = 0;
	is_negative = 1;
	result = (t_atof *) malloc(sizeof(t_atof));
	result->number = 0;
	result->error = 0;
	if (str[i] == 43 && str[i + 1] != 45)
		i++;
	if (str[i] == 45)
	{
		is_negative = -1;
		i++;
	}
	while (!result->error && str[i])
	{
		if (!ft_isdigit(str[i]))
			result->error = NOT_A_NUMBER;
		ft_check_overflow(&result, str[i]);
		result->number = (result->number * 10) + (str[i] - 48);
		i++;
	}
	result->number = result->number * is_negative;
	return (result);
}

static void	ft_check_overflow(t_atof **result, char next)
{
	if ((*result)->number > 2147483648 / 10
		|| ((*result)->number == 2147483647 / 10 && next - 48 > 7))
		(*result)->error = OVERFLOW;
}
