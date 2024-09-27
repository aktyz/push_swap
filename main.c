/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zslowian <zslowian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:36:05 by zslowian          #+#    #+#             */
/*   Updated: 2024/09/27 17:56:08 by zslowian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_input(char *input);

int main(int argc, char *argv[])
{
	if (!argc || argc < 2)
		return (0);
	else
		sort_input(argv[1]);
	return (0);
}

void	sort_input(char *input)
{

}
