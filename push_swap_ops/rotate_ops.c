/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:16:48 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/24 11:15:51 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	if (rotate(data->a))
		ft_printf("ra\n");
	else
		print_error(-26, data);
}

void	rb(t_data *data)
{
	if (rotate(data->b))
		ft_printf("rb\n");
	else
		print_error(-27, data);
}

void	rr(t_data *data)
{
	int	result1;
	int	result2;

	result1 = rotate(data->a);
	result2 = rotate(data->b);
	if (result1 == 1 && result2 == 1)
		ft_printf("rr\n");
	else
		print_error(-28, data);
}
