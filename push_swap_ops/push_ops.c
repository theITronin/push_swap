/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:15:23 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/29 18:17:25 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	if (push(data->a, data->b))
	{
		data->ops_counter[0]++;
		print_op_name(__func__);
	}
}

void	pb(t_data *data)
{
	if (push(data->b, data->a))
	{
		data->ops_counter[1]++;
		print_op_name(__func__);
	}
}

