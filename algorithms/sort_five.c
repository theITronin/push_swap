/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 22:11:59 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/31 22:14:12 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_small_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	push_min_to_b(t_data *data)
{
	int	index;
	int	size;

	index = find_min_node(data);
	size = data->a->size;
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(data);
	}
	else
	{
		index = size - index;
		while (index-- > 0)
			rra(data);
	}
	pb(data);
}

void	sort_five_or_less(t_data *data)
{
	if (is_small_sorted(data->a))
		return ;
	while (data->a->size > 3)
		push_min_to_b(data);
	sort_three_or_less(data);
	while (data->b->size > 0)
		pa(data);
}
