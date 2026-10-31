/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabbenit <pabbenit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:23:20 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/31 22:31:51 by pabbenit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_management(t_data *data)
{
	if (data->disorder != 0.0)
	{
		if (data->id_flag == SIMPLE)
			alg_simple(data);
		else if (data->id_flag == MEDIUM)
			alg_medium(data);
		else if (data->id_flag == COMPLEX)
			alg_complex(data);
		else if (data->a->size <= 3)
			sort_three_or_less(data);
		else if (data->a->size <= 5)
			sort_five_or_less(data);
		else
			alg_adaptive(data);
	}
	if (data->check_bench == 1)
		bench(data);
}
