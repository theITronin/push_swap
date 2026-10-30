/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:41 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/29 18:20:07 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	data->ops_counter[8]++;
	if (reverse_rotate(data->a))
	{
		print_op_name(__func__);
	}
}

void	rrb(t_data *data)
{
	data->ops_counter[9]++;
	if (reverse_rotate(data->b))
	{
		print_op_name(__func__);
	}
}

void	rrr(t_data *data)
{
	int	result1;
	int	result2;
	
	data->ops_counter[10]++;
	result1 = reverse_rotate(data->a);
	result2 = reverse_rotate(data->b);
	if (result1 == 1 && result2 == 1)
	{
		print_op_name(__func__);
	}
}
