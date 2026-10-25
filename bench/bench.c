/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:31:22 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/25 14:11:53 by dbustama         ###   ########.fr       */
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

void	bench(t_data *data, char *strategy)
{
	int	disorder;

	disorder = data->disorder * 10000;
	ft_printf("[bench] disorder: %d.%d", disorder / 100, disorder % 100);
	ft_printf("[bench] strategy: %s", strategy);
	ft_printf("[bench] total_ops: %d", total_ops(data));
}

