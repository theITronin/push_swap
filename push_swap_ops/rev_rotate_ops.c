/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:41 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/24 19:18:57 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (reverse_rotate(data->a))
	{
		if (!data->check_bench)
			write(2, __func__, 2);
	}
}

void	rrb(t_data *data)
{
	if (reverse_rotate(data->b))
	{
		if (!data->check_bench)
			write(2, __func__, 2);
	}
}

void	rrr(t_data *data)
{
	int	result1;
	int	result2;
	
	result1 = reverse_rotate(data->a);
	result2 = reverse_rotate(data->b);
	if (result1 == 1 && result2 == 1)
	{
		if (!data->check_bench)
			write(2, __func__, 2);
	}
}
