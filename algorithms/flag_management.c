/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:23:20 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/26 16:18:50 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_management(t_data *data)
{
	unsigned char	*strategy;

	strategy = NULL;
	if (data->id_flag == SIMPLE)
	{
		alg_simple(data);
		strategy = "Simple / O(n^2)";
	}
	else if (data->id_flag == MEDIUM)
	{
		alg_medium(data);
		strategy = "Medium / O(n√n)";
	}
	else if (data->id_flag == COMPLEX)
	{
		alg_complex(data);
		strategy = "Complex / O(n log n)";
	}
	else
	{
		alg_adaptive(data);
		strategy = "Adaptive / "; // Adaptive manage of the big O notation in bench is missing.
	}
	if (data->check_bench == 1)
		bench(data, strategy);
}
