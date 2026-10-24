/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbustama <dbustama@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:56:04 by dbustama          #+#    #+#             */
/*   Updated: 2026/10/24 20:54:42 by dbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	t_stack *a;
	t_stack	*b;
	
	data->a = NULL;
	data->b = NULL;
	a = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!a)
		print_error(-1, data);
	b = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!b)
		print_error(-1, data);
	data->id_flag = INVALID_FLAG;
	data->a = a;
	data->b = b;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 1)
		return (-1);
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!data)
		print_error(-1, data);
	init_data(data);
	parse_params(argc, argv, data);
	print_stack(data->a);
	algorithm_management(data);
	return (0);
}
