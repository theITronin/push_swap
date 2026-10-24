/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:41 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/24 11:16:59 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	if (reverse_rotate(data->a))
		ft_printf("rra\n");
	else
		print_error(-29, data);
}

void	rrb(t_data *data)
{
	if (reverse_rotate(data->b))
		ft_printf("rrb\n");
	else
		print_error(-30, data);
}

void	rrr(t_data *data)
{
	int	result1;
	int	result2;
	
	result1 = reverse_rotate(data->a);
	result2 = reverse_rotate(data->b);
	if (result1 == 1 && result2 == 1)
		ft_printf("rrr\n");
	else
		print_error(-31, data);
}
