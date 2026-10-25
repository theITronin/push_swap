/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbv <pbv@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:23:20 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/25 18:31:35 by pbv              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_management(t_data *data)
{
	char	*strategy;

	strategy = NULL;
	if (data->id_flag == SIMPLE)
	{
		alg_simple(data);
		strategy = "Simple / O(n^2)"; // La norma prohíbe caracteres fuera de ASCII
	}
	else if (data->id_flag == MEDIUM)
	{
		alg_medium(data);
		strategy = "Medium / ";
	}
	else if (data->id_flag == COMPLEX)
	{
		alg_complex(data);
		strategy = "Complex / ";

	}
	else
	{
		alg_adaptive(data);
		strategy = "Adaptive / ";
	}
	if (data->check_bench == 1)
		bench(data, strategy);
}
