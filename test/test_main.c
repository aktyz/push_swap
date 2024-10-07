/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:56:45 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/07 15:24:11 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	char		*str;
	t_heap		*a;

	str = ft_calloc(sizeof(char), 20);
	ft_strlcpy(str, "33", 10);	
	ft_printf("%s\n", str);
	a = parse_arg(str);
	ft_printf("My frist number: %d\n", a->number);
	return (0);
}