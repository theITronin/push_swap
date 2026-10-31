/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:28:31 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 11:39:41 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max_index;
	int	counter;

	max_index = size - 1;
	counter = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		counter++;
	}
	return (counter);
}

void	alg_complex(t_data *data)
{
	int	i;
	int	bit;
	int	max_bits;
	int	size;

	bit = 0;
	size = data->a->size;
	max_bits = get_max_bits(size);
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((data->a->head->n_index >> bit) & 1) == 0)
				pb(data);
			else
				ra(data);
			i++;
		}
		while (data->b->size > 0)
			pa(data);
		bit++;
	}
}
