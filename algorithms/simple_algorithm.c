/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:29:52 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/27 17:34:20 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_node(t_data *data)
{
	t_node	*node;
	int		i;
	int		min_index;
	int		min_value;
	
	node = data->a->head;
    if (node == NULL)
		return (-1);
	min_value = node->value;
	min_index = 0;
	i = 0;
	while (i < data->a->size)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_index = i;
		}
		node = node->next;
		i++;
	}
	return (min_index);
}

void	alg_simple(t_data *data)
{
	int	index;
	int	size;	

	while (data->a->size > 0)
	{
		index = find_min_node(data);
		size = data->a->size;
		if (index > size / 2)
		{
			index = size - index;
			while (index-- > 0)
				rra(data);
		}
		else
		{
			while (index-- > 0)
				ra(data);
		}
		pb(data);
	}
	while (data->b->size > 0)
		pa(data);
	
}
