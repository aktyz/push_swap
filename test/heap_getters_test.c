/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_getters_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:57:42 by zslowian          #+#    #+#             */
/*   Updated: 2024/10/14 15:48:57 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_get_size(void);

void	test_ft_get_size(void)
{
	t_heap	*heap;
	int		size;
	int		i;

	heap = ft_heapnew(33);
	size = ft_get_size(heap);
	if (size != 1)
		ft_printf("Test 1 ft_get_size failed, expected: 1, got: %d\n", size);
	free(heap);
	heap = 0;
	size = ft_get_size(heap);
	if (size != 0)
		ft_printf("Test 2 ft_get_size failed, expected: 0, got: %d\n", size);
	size = 7;
	heap = ft_heapnew(1);
	i = 1;
	while (size-- > 0)
	{
		ft_heapadd(size, &heap);
		i++;
	}
	size = ft_get_size(heap);
	if (size != 8)
		ft_printf("Test 2 ft_get_size failed, expected: 8, got: %d\n", size);
}