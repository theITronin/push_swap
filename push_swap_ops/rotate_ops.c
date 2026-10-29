/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:48 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/29 18:20:30 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	data->ops_counter[5]++;
	if (rotate(data->a))
	{
		write(2, __func__, 3);
		write(1, "\n", 1);
	}
}

void	rb(t_data *data)
{
	data->ops_counter[6]++;
	if (rotate(data->b))
	{
		write(2, __func__, 3);
		write(1, "\n", 1);
	}
}

void	rr(t_data *data)
{
	int	result1;
	int	result2;

	result1 = rotate(data->a);
	result2 = rotate(data->b);
	data->ops_counter[7]++;
	if (result1 == 1 && result2 == 1)
	{
		write(2, __func__, 3);
		write(1, "\n", 1);
	}
}
