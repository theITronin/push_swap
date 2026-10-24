/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:48 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/24 19:21:08 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (rotate(data->a))
	{
		if (!data->check_bench)
			write(2, __func__, 2);
	}
}

void	rb(t_data *data)
{
	if (rotate(data->b))
	{
		if (!data->check_bench)
			write(2, __func__, 2);
	}
}

void	rr(t_data *data)
{
	int	result1;
	int	result2;

	result1 = rotate(data->a);
	result2 = rotate(data->b);
	if (result1 == 1 && result2 == 1)
	{
		if (!data->check_bench)
			write(2, __func__, 2);
	}
}
