/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:29:03 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/29 20:21:33 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	n;

	if (nb < 0)
		return (0);
	n = 1;
	while (n <= 46340)
	{
		if (nb == n * n)
			return (n);
		if (nb < n * n)
			return (n);
		n++;
	}
	return (0);
}

int	find_max_node(t_data *data)
{
	t_node	*node;
	int		i;
	int		max_index;
	int		max_value;
	
	node = data->b->head;
    if (node == NULL)
		return (-1);
	max_value = node->value;
	max_index = 0;
	i = 0;
	while (i < data->b->size)
	{
		if (node->value > max_value)
		{
			max_value = node->value;
			max_index = i;
		}
		node = node->next;
		i++;
	}
	return (max_index);
}

void	sort_b(t_data *data)
{
	int	index;
	int	size;	

	while (data->b->size > 0)
	{
		index = find_max_node(data);
		size = data->b->size;
		if (index > size / 2)
		{
			index = size - index;
			while (index-- > 0)
				rrb(data);
		}
		else
		{
			while (index-- > 0)
				rb(data);
		}
		pa(data);
	}
}

void	alg_medium(t_data *data)
{
	int		k;
	int		k_index;
	int		size;
	t_node	*node;

    k = ft_sqrt(data->a->size);
	k_index = 0;
	while (data->a->size > 0)
	{
		size = 0;
		k_index = k_index + k;
		while (size <= data->a->size)
		{
			node = data->a->head;
			if (node->n_index < k_index)
				pb(data);
			else
				ra(data);
			size++;
		}
	}
	sort_b(data);
}

