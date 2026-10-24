/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:15:54 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/24 11:49:47 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (swap(data->a))
		ft_printf("sa\n");
	else
		print_error(-23, data);
}

void	sb(t_data *data)
{
	if (swap(data->b))
		ft_printf("sb\n");
	else
		print_error(-24, data);
}

void	ss(t_data *data)
{
	int	result1;
	int	result2;
	
	result1 = swap(data->a);
	result2 = swap(data->b);
	if (result1 == 1 && result2 == 1)
		ft_printf("ss\n");
	else
		print_error(-25, data);
}