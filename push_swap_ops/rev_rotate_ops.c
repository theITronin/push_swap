/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:41 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 21:45:26 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (reverse_rotate(data->a))
	{
		data->ops_counter[8]++;
		print_op_name(__func__, data);
	}
}

void	rrb(t_data *data)
{
	if (reverse_rotate(data->b))
	{
		data->ops_counter[9]++;
		print_op_name(__func__, data);
	}
}

void	rrr(t_data *data)
{
	int	result1;
	int	result2;

	result1 = reverse_rotate(data->a);
	result2 = reverse_rotate(data->b);
	if (result1 == 1 || result2 == 1)
	{
		data->ops_counter[10]++;
		print_op_name(__func__, data);
	}
}
