/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:31:22 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/25 10:22:37 by dbustama         ###   ########.fr       */
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

void	bench(t_data *data)
{
	ft_printf("[bench]");
	ft_printf("[bench] total_ops: %d", total_ops(data));
}
