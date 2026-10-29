/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:15:54 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/29 18:22:21 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (swap(data->a))
	{
		data->ops_counter[2]++;
		write(2, __func__, 3);
		write(1, "\n", 1);
	}
}

void	sb(t_data *data)
{
	if (swap(data->b))
	{
		data->ops_counter[3]++;
		write(2, __func__, 3);
		write(1, "\n", 1);
	}
}

void	ss(t_data *data)
{
	int	result1;
	int	result2;
	
	result1 = swap(data->a);
	result2 = swap(data->b);
	data->ops_counter[4]++;
	if (result1 == 1 && result2 == 1)
	{
		write(2, __func__, 3);
		write(1,"\n", 1);
	}
}