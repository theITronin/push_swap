/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:31:22 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 17:49:34 by dbustama         ###   ########.fr       */
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

char	*print_o_adaptive(t_data *data)
{
	if (data->disorder < 0.2)
		return ("O(n^2)\n");
	else if (data->disorder < 0.5)
		return ("O(n√n)\n");
	else
		return ("O(n log n)\n");
}

void	print_disorder(t_data *data)
{
	int	disorder;
	int	double_disorder;

	disorder = data->disorder * 10000;
	double_disorder = disorder % 100;
	if (double_disorder < 10)
		double_disorder = double_disorder * 10;
	if (data->disorder == 0.0)
		ft_printf_error("[bench] disorder: 00.00%%\n");
	else if (double_disorder == 0)
		ft_printf_error("[bench] disorder: %d.00%%\n", disorder / 100);
	else
		ft_printf_error("[bench] disorder: %d.%d%%\n", disorder / 100, double_disorder);
}

void	bench(t_data *data)
{
	print_disorder(data);
	if (data->id_flag == SIMPLE)
		ft_printf_error("[bench] Simple / O(n^2)\n");
	else if (data->id_flag == MEDIUM)
		ft_printf_error("[bench] Medium / O(n√n)\n");
	else if (data->id_flag == COMPLEX)
		ft_printf_error("[bench] Complex / O(n log n)\n");
	else
		ft_printf_error("[bench] Adaptive / %s", print_o_adaptive(data));
	ft_printf_error("[bench] total_ops: %d\n", total_ops(data));
	ft_printf_error("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d \n",
		data->ops_counter[2], data->ops_counter[3], data->ops_counter[4],
		data->ops_counter[0], data->ops_counter[1]);
	ft_printf_error("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		data->ops_counter[5], data->ops_counter[6], data->ops_counter[7],
		data->ops_counter[8], data->ops_counter[9], data->ops_counter[10]);
}
