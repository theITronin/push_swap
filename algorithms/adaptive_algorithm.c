/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:29:00 by pbv               #+#    #+#             */
/*   Updated: 2026/10/30 19:52:12 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_adaptive(t_data *data)
{
	if (data->disorder < 0.2)
		alg_simple(data);
	else if (data->disorder < 0.5)
		alg_medium(data);
	else
		alg_complex(data);
}
