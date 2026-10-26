/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:31:22 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/26 16:19:00 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(t_data *data)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < 11)
	{
		n = n + data->ops_counter[i];
		i++;
	}
	return (n);
}

void	bench(t_data *data, unsigned char *strategy)
{
	int	disorder;

	disorder = data->disorder * 10000;
	ft_printf("[bench] disorder: %d.%d\n", disorder / 100, disorder % 100);
	ft_printf("[bench] strategy: %s\n", strategy);
	ft_printf("[bench] total_ops: %d\n", total_ops(data));
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d \n", 
		data->ops_counter[2], data->ops_counter[3], data->ops_counter[4], data->ops_counter[0], data->ops_counter[1]);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", 
		data->ops_counter[5], data->ops_counter[6], data->ops_counter[7], data->ops_counter[8], data->ops_counter[9], data->ops_counter[10]);
}

