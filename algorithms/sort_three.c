/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 22:10:24 by pabbenit          #+#    #+#             */
/*   Updated: 2026/10/31 22:14:31 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->head->value;
	b = data->a->head->next->value;
	c = data->a->head->next->next->value;
	if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && a > c)
		ra(data);
	else if (a > b)
		sa(data);
	else if (b > c && a > c)
		rra(data);
	else if (b > c)
	{
		sa(data);
		ra(data);
	}
}

void	sort_three_or_less(t_data *data)
{
	if (data->a->size < 2)
		return ;
	if (data->a->size == 2)
	{
		if (data->a->head->value > data->a->head->next->value)
			sa(data);
		return ;
	}
	sort_three(data);
}
