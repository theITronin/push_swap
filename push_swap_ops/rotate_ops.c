/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:48 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 21:45:49 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (rotate(data->a))
	{
		data->ops_counter[5]++;
		print_op_name(__func__, data);
	}
}

void	rb(t_data *data)
{
	if (rotate(data->b))
	{
		data->ops_counter[6]++;
		print_op_name(__func__, data);
	}
}

void	rr(t_data *data)
{
	int	result1;
	int	result2;

	result1 = rotate(data->a);
	result2 = rotate(data->b);
	if (result1 == 1 || result2 == 1)
	{
		data->ops_counter[7]++;
		print_op_name(__func__, data);
	}
}
