/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:23:20 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/27 17:39:35 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_management(t_data *data)
{
	unsigned char	*strategy;

	strategy = NULL;
	if (data->id_flag == SIMPLE)
		alg_simple(data);
	else if (data->id_flag == MEDIUM)
		alg_medium(data);
	else if (data->id_flag == COMPLEX)
		alg_complex(data);
	else
		alg_adaptive(data);
	if (data->check_bench == 1)
		bench(data);
}
