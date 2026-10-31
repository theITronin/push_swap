/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:15:54 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 21:47:44 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (swap(data->a))
	{
		data->ops_counter[2]++;
		print_op_name(__func__, data);
	}
}

void	sb(t_data *data)
{
	if (swap(data->b))
	{
		data->ops_counter[3]++;
		print_op_name(__func__, data);
	}
}

void	ss(t_data *data)
{
	int	result1;
	int	result2;

	result1 = swap(data->a);
	result2 = swap(data->b);
	if (result1 == 1 || result2 == 1)
	{
		data->ops_counter[4]++;
		print_op_name(__func__, data);
	}
}
