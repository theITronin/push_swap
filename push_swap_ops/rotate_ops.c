/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:48 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/30 20:01:54 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	data->ops_counter[5]++;
	if (rotate(data->a))
		print_op_name(__func__, data);
}

void	rb(t_data *data)
{
	data->ops_counter[6]++;
	if (rotate(data->b))
		print_op_name(__func__, data);
}

void	rr(t_data *data)
{
	int	result1;
	int	result2;

	result1 = rotate(data->a);
	result2 = rotate(data->b);
	data->ops_counter[7]++;
	if (result1 == 1 && result2 == 1)
		print_op_name(__func__, data);
}
