/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:15:23 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/24 13:41:09 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	if (push(data->a, data->b))
		data->ops_counter[0]++;
		if (!data->check_bench)
			ft_printf("pa\n");
	else
		print_error(-21, data);
}

void	pb(t_data *data)
{
	if (push(data->b, data->a))
		data->ops_counter[1]++;
		if (!data->check_bench)
			ft_printf("pb\n");
	else
		print_error(-22, data);
}

