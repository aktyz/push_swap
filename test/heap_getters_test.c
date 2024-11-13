/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_getters_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:57:42 by zslowian          #+#    #+#             */
/*   Updated: 2024/11/13 14:36:12 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_ft_get_size(void);
void	test_ft_get_nb_pos(void);

void	test_ft_get_size(void)
{
	t_heap	*heap;
	int		size;
	int		i;

	ft_printf("\n---------------------Testing ft_get_size---------------------\n");
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

void	test_ft_get_nb_pos(void)
{
	t_heap	*heap;
	int		result;

	ft_printf("\n---------------------Testing ft_get_nb_pos---------------------\n");
	heap = 0;
	heap = ft_heapnew(1);
	ft_heapadd(2, &heap);
	ft_heapadd(3, &heap);
	ft_heapadd(4, &heap);
	ft_heapadd(5, &heap);
	ft_heapadd(6, &heap);
	result = ft_get_nb_pos(4, heap);
	if (result != 3)
		ft_printf("Test failed, expected: 3, got: %d\n", result);
	result = ft_get_nb_pos(88, heap);
	if (result != -1)
		ft_printf("Test failed, expected: -1, got: %d\n", result);
}