/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:23:20 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/25 12:01:28 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_management(t_data *data)
{
	if (data->id_flag == 0)
		alg_simple(data);
	else if (data->id_flag == 1)
		alg_medium(data);
	else if (data->id_flag == 2)
		alg_complex(data);
	/*else
		alg_adaptive(data);*/
	if (data->check_bench == 1)
		bench(data);
}
