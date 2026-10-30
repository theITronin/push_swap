/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:28:31 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/30 14:06:22 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
