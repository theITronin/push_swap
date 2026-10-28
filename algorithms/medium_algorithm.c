/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbv <pbv@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 09:29:03 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/25 18:22:06 by pbv              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	n;

	if (nb < 0)
		return (0);
	n = 1;
	while (n <= 46340)
	{
		if (nb == n * n)
			return (n);
		if (nb < n * n)
			return (0);
		n++;
	}
	return (0);
}

void	alg_medium(t_data *data)
{
	int k;
    int i;

    k = ft_sqrt(data->a->size);   
}
