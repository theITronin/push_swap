/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:29:03 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/28 18:24:02 by dbustama         ###   ########.fr       */
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

void	sort_b(data)
{

}

void	push_node(int	node_index, t_data *data)
{
	int	size;

	size = data->a->size;
	if (node_index > size / 2)
	{
		node_index = size - node_index;
		while (node_index-- > 0)
			rra(data);
	}
	else
	{
		while (node_index-- > 0)
			ra(data);
	}
	pb(data);
}

void	alg_medium(t_data *data)
{
	int		k;
	int		node_index;
	int		chunks;
	t_node	*node;

    k = ft_sqrt(data->a->size);
	chunks = data->a->size / k;
	while (chunks > 0)
	{
		node = data->a->head;
		k = k + k;
		node_index = 0;
		while (node)
		{
			if (node->n_index < k)
			{
				node = node->next;
				push_node(node_index, data);
			}
			node_index++;
			node = node->next;
		}
		sort_b(data);
		chunks--;
	}
}
