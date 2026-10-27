/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbv <pbv@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:29:52 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/25 18:21:27 by pbv              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	find_min_node(t_data *data)
{
	int		i;
	int		index;
	t_node	*min_node;
	t_node	*node;

	i = 0;
	index = 0;
	min_node = get_node_at(data->a, i);
	i++;
    while (i <= data->a->size)
	{
		node = get_node_at(data->a, i);
		if (min_node->value > node->value)
		{
			min_node = node;
			index = i;
		}
		i++;
	}
	return (index);
}

void	alg_simple(t_data *data)
{
	int		index;
	t_node	*node;

	while (data->a->size != 0)
	{
		index = find_min_node(data);
		node = get_node_at(data->a, index);
		if (index > data->a->size / 2)
		{
			while (node != data->a->head)
				ra(data);
		}
		else if (index <= data->a->size / 2)
		{
			while (node != data->a->head)
				rra(data);
		}
		while (data->b->size != 0)
			pb(data);
	}
}
